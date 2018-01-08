#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "modelo_3D.h"
#include "cubo.h"
#include "tetraedro.h"
#include "cilindro.h"
#include <file_ply_stl.h>
#include "esfera.h"
#include "cono.h"
#include "tubo.h"
#include "vaso.h"
#include "vaso_i.h"
#include "reguladorW.h"
#include "luz.h"
#include "material.h"
#include "textura.h"


class Escena {
private:
// tamaño de los ejes
#define AXIS_SIZE 5000
Ejes ejes;
modelo_3D m3D;
modelo_3D auxB;
Cubo cubo;
Tetraedro tetraedro;
_file_ply modeloPly;
Cilindro cilindro;
Esfera esfera;
Cono cono;
Tubo tubo;
Vaso vaso;
Vaso_i vaso_i;
reguladorW regulador;
Luz luz1;
Luz luz2;
GLfloat angulo;
bool luzActiva;
int tecla;
int nBarrido;
bool esferaCargada;
int tapas;
float Tl;
int modo;
double rotar;
int es;
double velocidad;
Textura textura;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformación de cámara
	void change_projection();
	void change_observer();


public:
     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void girar_watt();
	void dibujar() ;
	

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
};
#endif
