
#include <camara.h>


Camara::Camara(){

	Front_plane=50;
    Back_plane=2000;
    Width=200;
    Height=200;

}

void Camara::actualizar(GLfloat Widt, GLfloat Heigh, GLfloat Front_plan, GLfloat Back_plan){

		Width = Widt;
		Height = Heigh;
		Front_plane = Front_plan;
		Back_plane = Back_plan;

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