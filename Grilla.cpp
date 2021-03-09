#include "Grilla.h"
#include <cstdlib>

Grilla::Grilla(unsigned int fil, unsigned int col, unsigned int tamCel): fil(fil), col(col), tamCel(tamCel){
   celdas = new Celda**[fil];
   inicial[0]=-1;
   inicial[1]=-1;
   objetivo[0]=-1;
   objetivo[1]=-1;
   for(int i=0; i<fil; i++){
      celdas[i] = new Celda*[col];
      for(int j=0; j<col; j++)
	 celdas[i][j]=new Celda(j,i,tamCel); //Creo col*fil celdas
   }
}

void Grilla::display(RenderWindow &window){
   for(int i=0; i<fil; i++){
      for(int j=0; j<col;j++)
         celdas[i][j]->draw(window);
   }
   if(inicial[0]>-1 && objetivo[0] > -1)
      window.draw(linea, 2, Lines); //Si existen tanto el inicial como objetivo dibujo la linea q los une
}

void Grilla::reset(){
   for(int i=0; i<fil; i++){
      for(int j=0; j<col; j++)
	 celdas[i][j]->setEstado(Celda::Desconocida);
   }
}

void Grilla::pintarLinea(){
      Vector2f aux;//Vector auxiliar para calcular la linea
      aux = celdas[objetivo[0]][objetivo[1]]->forma.getPosition();
      aux.x += (tamCel/2);
      aux.y += (tamCel/2);
      linea[1].position = aux;
      linea[1].color = Color::Blue;
      aux = celdas[inicial[0]][inicial[1]]->forma.getPosition();
      aux.x += (tamCel/2);
      aux.y += (tamCel/2);
      linea[0].position = aux;
      linea[0].color = Color::Blue;
} 

void Grilla::setInicial(int x, int y){
   if(fueraDeRango(x,y))
      return;
   if(inicial[0] < 0 || inicial[1] < 0){
      celdas[y][x]->setEstado(Celda::Inicio);
   }
   else{
      celdas[inicial[0]][inicial[1]]->setEstado(Celda::Desconocida);
      celdas[y][x]->setEstado(Celda::Inicio);
   }
   inicial[0]=y; inicial[1]=x;
   //if(objetivo[0] > -1)
     // pintarLinea();
}

void Grilla::setObjetivo(int x, int y){
   if(fueraDeRango(x,y))
      return;
   if(objetivo[0]<0 || objetivo[1]<0){
      celdas[y][x]->setEstado(Celda::Objetivo);
   }
   else{  
      celdas[objetivo[0]][objetivo[1]]->setEstado(Celda::Desconocida);
      celdas[y][x]->setEstado(Celda::Objetivo);
   }
   objetivo[0]=y;
   objetivo[1]=x;
   //if(inicial[0] > -1)
     // pintarLinea();
}

void Grilla::setVecinos(int x, int y){
   if(fueraDeRango(x,y))
      return;
   int aux2=0;
   /*for(int i = -1; i < 2; i++){ //Puede calcular los 8 vecinos, lo deje x si pinta reimplementarlo
      for(int j = -1; j < 2; j++){
	 if(col > (x+j) && (x+j) >= 0 && fil >(y+i) &&(y+i) >= 0){
	    if(j==0 && i==0)
	       continue; //Una celda no es vecina de si misma
	    celdas[y][x]->vecinos[aux2]=celdas[y+i][x+j]; //Agrego los n punteros vecinos a la celda
	    aux2++;
	 }
      }
   }*/
   if(x-1 >= 0){
      celdas[y][x]->vecinos[aux2]=celdas[y][x-1];
      aux2++;
   }
   if(x+1 < col){
      celdas[y][x]->vecinos[aux2]=celdas[y][x+1];
      aux2++;
   }
   if(y-1 >= 0){
      celdas[y][x]->vecinos[aux2]=celdas[y-1][x];
      aux2++;
   }
   if(y+1 < fil){
      celdas[y][x]->vecinos[aux2]=celdas[y+1][x];
      aux2++;
   } 
   celdas[y][x]->cantVec = aux2;
}

void Grilla::pintarVecinos(int x, int y){
   if(fueraDeRango(x,y))
      return;
   if(celdas[y][x]->cantVec < 0)
      setVecinos(x,y);
   for(int i=0; i < celdas[y][x]->cantVec; i++)
      celdas[y][x]->vecinos[i]->setEstado(Celda::Estado::Camino);
}

void Grilla::setEstado(int x, int y, Celda::Estado e){
   if(fueraDeRango(x,y))
      return;
   celdas[y][x]->setEstado(e);
   //Si pisa el objetivo/inicio con una pared se resetea
   if(y==inicial[0] && x==inicial[1]){
      inicial[0]=-1;
      inicial[1]=-1;
   }
   if(y==objetivo[0] && x==objetivo[1]){
      objetivo[0]=-1;
      objetivo[1]=-1;
   }
}

bool Grilla::fueraDeRango(int x, int y){
   return (x < 0 || x > col || y < 0 || y > fil);
}
