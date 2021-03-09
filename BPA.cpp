#include "BPA.h"
#include <stdio.h>
#include <unistd.h>

BPA::BPA(Grilla* x, sf::RenderWindow* window):grilla(x),window(window){}

bool BPA::testObjetivo(Nodo* x){
   return (obj->posX == x->posX && obj->posY == x->posY);
}

void BPA::actualizar(){
   delete obj;
   delete ini;
   obj = new Nodo(grilla->objetivo[1], grilla->objetivo[0]);
   ini = new Nodo(grilla->inicial[1], grilla->inicial[0]);
}

bool BPA::expandir(Nodo* x){
   explorados.insertar(x);
   grilla->setVecinos(x->posX, x->posY);
   Celda* auxiliar = grilla->celdas[x->posY][x->posX];
   Nodo* aux;
   for(int i=0; i < auxiliar->cantVec; i++){
      if(auxiliar->vecinos[i]->e==Celda::Estado::Pared)
	 continue;
      aux = new Nodo(auxiliar->vecinos[i]->posX, auxiliar->vecinos[i]->posY);
      aux->padre=x;
      grilla->celdas[aux->posY][aux->posX]->setEstado(Celda::Estado::Visitada);
      grilla->display(*window);
      window->display();
      //usleep(200);

      if(testObjetivo(aux)){
	 delete nodoSol;
	 nodoSol = aux;
	 return true;
      }
      if(!explorados.insertar(aux)){
	 delete aux;
	 continue;
      }
      frontera.push(aux);
   }
   return false;
}

void BPA::buscar(){
   Nodo* aux;
   yaBusque=true;
   frontera.push(new Nodo(grilla->inicial[1], grilla->inicial[0]));
   actualizar();
   while(true){
      if(frontera.empty()){
	 limpiar();
	 return;
      }
      aux = frontera.front();
      frontera.pop();
      if(expandir(aux))
	 break;
   }
   aux = nodoSol->padre;
   while(aux != NULL){
      grilla->setEstado(aux->posX, aux->posY, Celda::Estado::Camino);
      aux = aux->padre;
   } 
   grilla->setEstado(obj->posX,obj->posY, Celda::Estado::Objetivo);
   grilla->setEstado(ini->posX,ini->posY, Celda::Estado::Inicio);
   limpiar();
}

void BPA::limpiar(){
   while(frontera.size())
      frontera.pop();
   explorados.limpiar();
} 
