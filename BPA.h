#ifndef BPA_H
#define BPA_H

#include <queue>
#include "Set.h"
#include "Grilla.h"

class BPA{
   public:
      sf::RenderWindow* window;
      Set explorados;
      std::queue<Nodo*> frontera;
      Nodo* obj=NULL;
      Nodo* ini=NULL;
      Nodo* nodoSol=NULL;
      Grilla* grilla;
      bool yaBusque=false;
   public:
      BPA(Grilla* x, sf::RenderWindow* window);
      void actualizar();
      bool testObjetivo(Nodo* x); 
      bool expandir(Nodo* x);
      void buscar();
      void limpiar();
};

#endif //BPA_H
