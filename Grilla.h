#ifndef GRILLA_H
#define GRILLA_H
#include "Celda.h"

class Grilla{
   public:
      unsigned int fil, col, tamCel; //Cantidad de filas, columnas, pixeles de celda
      int tamVec;
      int inicial[2];//Guarda la posicion del inicial
      int objetivo[2];//Guarda la posicion del objetivo
      Celda*** celdas;//Matriz de Punteros celdas
      Vertex linea[2];//Linea que une inicial y objetivo

   public:
      Grilla(unsigned int fil, unsigned int col, unsigned int tamCel);
      void setVecinos(int x, int y); //Calcula los vecinos de la celda xy
      void pintarVecinos(int x, int y);//Pinta los vecinos
      void pintarLinea();
      void display(RenderWindow &window);
      void reset(); //Valor por defecto de la grilla
      void setEstado(int x, int y, Celda::Estado e); //Cambia el estado de la celda xy
      void setInicial(int x, int y); //Celda xy como inicia.
      void setObjetivo(int x, int y); //Celda xy como objetivo
      bool fueraDeRango(int x, int y);
};

#endif //GRILLA_H
