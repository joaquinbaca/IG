
#include <cubo.h>
#include <stdio.h>

Cubo::Cubo(){
Vertices.push_back(_vertex3f(-0.5,-0.5,-0.5));
Vertices.push_back(_vertex3f(0.5,-0.5,-0.5));
Vertices.push_back(_vertex3f(0.5,0.5,-0.5));
Vertices.push_back(_vertex3f(-0.5,0.5,-0.5));
Vertices.push_back(_vertex3f(-0.5,-0.5,0.5));
Vertices.push_back(_vertex3f(0.5,-0.5,0.5));
Vertices.push_back(_vertex3f(0.5,0.5,0.5));
Vertices.push_back(_vertex3f(-0.5,0.5,0.5));

Triangles.push_back(_vertex3i(0,3,1));
Triangles.push_back(_vertex3i(1,3,2));
Triangles.push_back(_vertex3i(1,2,5));
Triangles.push_back(_vertex3i(5,2,6));
Triangles.push_back(_vertex3i(5,6,4));
Triangles.push_back(_vertex3i(4,6,7));
Triangles.push_back(_vertex3i(4,7,0));
Triangles.push_back(_vertex3i(0,7,3));
Triangles.push_back(_vertex3i(4,0,5));
Triangles.push_back(_vertex3i(5,0,1));
Triangles.push_back(_vertex3i(3,7,2));
Triangles.push_back(_vertex3i(2,7,6));

calcularNormalesCaras();
  calcularNormalesVertices();

}
