#ifndef _INC_REGULADORW_H
#define _INC_REGULADORW_H
#include <modelo_3D.h>
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <math.h>
#include <vector>
#include <vertex.h>
#include <cubo.h>
#include <esfera.h>
#include <cilindro.h>
#include <cubo.h>
#include <file_ply_stl.h>

/////////////////esfera_mango////////////////////
class esfera_Mango : public modelo_3D{
private:	

Esfera esfera_N;


public:
esfera_Mango();
void draw(int modo);

};

///////////////////cilindro_superior///////////////////

class cilindro_superior : public modelo_3D{
private:	

Cilindro cilindro_N;
_file_ply modeloPly;
modelo_3D m3D;

public:
cilindro_superior();
void draw(int modo);

};

///////////////////Cilindro_anclaje///////////////////

class Cilindro_anclaje : public modelo_3D{
private:	
Cilindro cilindro_N;

public:
Cilindro_anclaje();
void draw(int modo);

};


///////////////////MANGO///////////////////

class Mango : public modelo_3D{
private:	

esfera_Mango esfera_Man;
cilindro_superior cilindro_sup;

public:
Mango();
void draw(int modo);

};

////////////////////mano_doble////////////////////

class Mano : public modelo_3D{
private:	

Mango mango;
Cilindro_anclaje cilindro_anclaje;



public:
Mano();
void draw(int modo,float T);

};


///////////////////cubo_union///////////////////

class Cubo_union : public modelo_3D{
private:	
Cubo cubo_n;
public:
Cubo_union();
void draw(int modo);

};


///////////////////Cubo_tope///////////////////

class Cubo_tope : public modelo_3D{
private:	
Cubo cubo_n;

public:
Cubo_tope();
void draw(int modo);

};

///////////////////Brazo_completo///////////////////

class Brazo_completo : public modelo_3D{
private:	

Mano mano;
Cubo_union cubo_union;
Cubo_tope cubo_tope;
public:
Brazo_completo();
void draw(float T,int modo);

};


///////////////////cuerpo///////////////////

class Cuerpo : public modelo_3D{
private:	
Cilindro cilindro_N;
Cubo cubo_n;
public:
Cuerpo();
void draw(int modo);

};
/////////regulador////////////////////////////////////
class reguladorW : public modelo_3D{
public:	

esfera_Mango esfera_Man;
cilindro_superior cilindro_sup;
Mango mango;
Cubo_union cubo_union;
Cilindro_anclaje cilindro_anclaje;
Cubo_tope cubo_tope;
Brazo_completo brazo_completo;
Cuerpo cuerpo;
Mano mano;

public:
reguladorW();
void draw_f(float T, int rotar,int modo);
};



////////////////////////////////////////








#endif /* _INC_REGULADORW_H */
