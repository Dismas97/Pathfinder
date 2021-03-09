#ifndef NODO_H
#define NODO_H

#include <cstddef>

class Nodo{
   public:
      Nodo* padre=NULL;
      Nodo* sig=NULL;
      int posX, posY;
      float c=0;
   public:
      Nodo();
      Nodo(int posX, int posY):posX(posX),posY(posY) {};
      void calculoCosto(Nodo x){c=x.c+1;};
      bool operator <(const Nodo& r) const {
	 return posX < r.posX && posY < r.posY;
      };
      bool operator==(const Nodo& r) const {
	 return posX==r.posX && posY == r.posY;
      };
      bool operator!=(const Nodo& r) const {
	 return posX!=r.posX || posY != r.posY;
      } 
};
#endif //NODO_H
