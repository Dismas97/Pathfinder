#ifndef CELDA_H
#define CELDA_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Celda{
   public:
      int posX, posY, tam; //Posicion x, y y tamañp de la celda
      RectangleShape techo, piso, paredIzq, paredDer, forma; //Contorno y relleno de la celda
      enum Estado {Visitada, Actual, Camino, Objetivo, Inicio, Pared, Desconocida} e; //Estado (color) de la celda
      Celda* vecinos[4]; //Vecinos de la celda max 4
      int cantVec=-1; //Al principio no tiene vecinos

   public:
      Celda(int posX, int posY, int tam); 
      void draw(RenderWindow &window);
      void setEstado(Estado e);
      void setColor(Color c);
};

#endif //CELDA_H
