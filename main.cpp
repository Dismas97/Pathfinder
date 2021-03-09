#include "BPA.h"

#define tamCel 40
#define largo 25
#define ancho 23

int main(){
   unsigned int tamX = ancho, tamY = largo;
   unsigned int celdaX, celdaY, posCelda;
   
   Grilla *grilla = new Grilla(tamY, tamX, tamCel);
   
   RenderWindow window({largo*tamCel, ancho*tamCel}, "Prueba");
   BPA *bpa = new BPA(grilla,&window); 

   while(window.isOpen()){
      window.clear();
      int cX, cY;
      grilla->display(window);
      if(Mouse::isButtonPressed(Mouse::Button::Left)){
	 Vector2i aux = Mouse::getPosition(window);
	 grilla->setEstado(aux.x/tamCel, aux.y/tamCel, Celda::Estado::Pared);
      }
      if(Mouse::isButtonPressed(Mouse::Button::Right)){
	 Vector2i aux = Mouse::getPosition(window);
	 grilla->setEstado(aux.x/tamCel, aux.y/tamCel, Celda::Estado::Desconocida);
      }
      if(Keyboard::isKeyPressed(Keyboard::Key::LControl)){
	 if(Mouse::isButtonPressed(Mouse::Button::Left)){
	    Vector2i aux = Mouse::getPosition(window);
	    cX = aux.x/tamCel;
	    cY = aux.y/tamCel;
	    if(cX >= tamX || cY >=tamY){
	       continue;
	    } 
	    grilla->setInicial(aux.x/tamCel,aux.y/tamCel);
	 }
	 if(Keyboard::isKeyPressed(Keyboard::Key::B) && !bpa->yaBusque){
	    bpa->actualizar();
	    bpa->buscar();
	 }
      }
      if(Keyboard::isKeyPressed(Keyboard::Key::LShift)){
	 if(Mouse::isButtonPressed(Mouse::Button::Left)){
	    Vector2i aux = Mouse::getPosition(window);
	    grilla->setObjetivo(aux.x/tamCel,aux.y/tamCel);
	 }
      }
      if(Keyboard::isKeyPressed(Keyboard::Key::V)){
	 if(Mouse::isButtonPressed(Mouse::Button::Left)){
	    Vector2i aux = Mouse::getPosition(window);
	    grilla->pintarVecinos(aux.x/tamCel,aux.y/tamCel);
	 }
      }
      if(Keyboard::isKeyPressed(Keyboard::Key::R)){
	 grilla->reset();
	 bpa->yaBusque=false;
      }
      
      if(Keyboard::isKeyPressed(Keyboard::Key::Escape))
	 window.close(); 
      window.display();
   }
}
