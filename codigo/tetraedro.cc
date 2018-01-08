
#include <tetraedro.h>
#include <stdio.h>

Tetraedro::Tetraedro(){
const int TAMANO = 1;
Vertices.push_back(_vertex3f(0,0,0));
Vertices.push_back(_vertex3f(TAMANO,0,0));
Vertices.push_back(_vertex3f(TAMANO/2,TAMANO,TAMANO/2));
Vertices.push_back(_vertex3f(TAMANO/2,0,TAMANO));

Triangles.push_back(_vertex3i(0,1,2));
Triangles.push_back(_vertex3i(2,1,3));
Triangles.push_back(_vertex3i(3,1,0));
Triangles.push_back(_vertex3i(0,2,3));

}
