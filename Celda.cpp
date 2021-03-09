#include "Celda.h"

Celda::Celda(int x, int y, int tam):posX(x),posY(y),tam(tam){
   setEstado(Desconocida); //Por defecto son desconocidas
   int grosor = 2; //Grosor del contorno de la celda
   
   //Generando contornos y relleno
   techo.setSize(Vector2f(tam, grosor));
   techo.setPosition(Vector2f(posX*tam, posY*tam));
   techo.setFillColor(Color::Black);

   paredDer.setSize(Vector2f(grosor, tam));
   paredDer.setPosition(Vector2f(posX * tam + tam, posY * tam));
   paredDer.setFillColor(Color::Black);

   piso.setSize(Vector2f(tam, grosor));
   piso.setPosition(Vector2f(posX * tam, posY * tam + tam));
   piso.setFillColor(Color::Black);

   paredIzq.setSize(Vector2f(grosor, tam));
   paredIzq.setPosition(sf::Vector2f(posX * tam, posY * tam));
   paredIzq.setFillColor(Color::Black);

   forma.setPosition(Vector2f(posX * tam, posY * tam));
   forma.setSize(sf::Vector2f(tam, tam));
   forma.setFillColor(Color::White);
}

void Celda::draw(RenderWindow &window){
   window.draw(forma);
   window.draw(techo);
   window.draw(piso);
   window.draw(paredIzq);
   window.draw(paredDer);

}

void Celda::setColor(Color c){
   forma.setFillColor(c);
}

void Celda::setEstado(Estado estado){
   switch(estado){
      case Visitada: forma.setFillColor(Color::Blue);break;
      case Actual: forma.setFillColor(Color::Cyan);break;
      case Camino: forma.setFillColor(Color::Green);break;
      case Objetivo: forma.setFillColor(Color::Red);break;
      case Inicio: forma.setFillColor(Color::Yellow);break;
      case Pared: forma.setFillColor(Color::Black);break;
      default: forma.setFillColor(Color::White);
   }
   e = estado;
}

