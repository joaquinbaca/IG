#ifndef _INC_MODELO_3D_H
#define _INC_MODELO_3D_H

#include <vector>
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vertex.h>
#include <material.h>



class modelo_3D{

public:	
vector <_vertex3f> Vertices;
vector <_vertex3i> Triangles;
vector <_vertex3f> normalesVertices;
vector <_vertex3f> normalesCaras;
Material Mat;
public:

modelo_3D();
void drawModo(int modo);
void drawPoints();
void drawSolid();
void drawLines();
void drawChess();
void generarBarrido(int n,int tapas);
_vertex3f GirarEY(_vertex3f p,float angulo);
void tapas(int n);
void setAmbiental(const _vertex4f &a);
void setDifusa(const _vertex4f &d);
void setEspecular(const _vertex4f &e);
void setBrillo(const GLfloat &b);
void activarM();
void calcularNormalesVertices();
void calcularNormalesCaras();
};
#endif /* _INC_MODELO_3D_H */

