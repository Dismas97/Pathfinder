#ifndef SET_H
#define SET_H
#include "Nodo.h"

class Set{
   public:
      Nodo* cursor;
      Nodo* curAux;
      Nodo* cabecera;
      int tam=0;
   public:
      bool buscar(Nodo *x){
	 if(!tam)
	    return false;
	 cursor = cabecera;
	 curAux = cursor;
	 while(cursor->sig != NULL && (*cursor != *x)){
	    curAux = cursor;
	    cursor = cursor->sig;
	 }
	 return *cursor == *x;
      };
      bool insertar(Nodo *x){
	 if(buscar(x))
	    return false;
	 if(!tam){
	    cabecera=x;
	    cabecera->sig=NULL;
	    tam++;
	    return true;
	 } 
	 cursor->sig = x;
	 x->sig=NULL;
	 tam++;
	 return true;
      };
      bool borrar(Nodo *x){
	 if(!buscar(x))
	    return false;
	 curAux->sig = cursor->sig;
	 delete cursor;
	 tam--;
	 return true;
      };
      void limpiar(){
	cursor = cabecera;
	curAux = cursor;
	while(cursor!=NULL){
	   cursor=cursor->sig;
	   delete curAux;
	   curAux = cursor;
	}
	tam=0;
	cabecera=NULL;
      }
};
#endif //SET_H
