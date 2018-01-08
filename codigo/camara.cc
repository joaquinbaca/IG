
#include <camara.h>


Camara::Camara(int x, int y){

}

void Camara::activar(){

}

void Camara::desactivar(){

}

void Camara::setOrtho(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-Width,Width,-Height,Height,Front_plane,Back_plane);


}

void Camara::setPerspectiva(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);

}

void Camara::setPosicion(int x,int y){

}