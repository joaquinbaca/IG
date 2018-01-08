#include "esfera.h"

Esfera::Esfera(){}

void Esfera::Redimensionar(int n){
        float PI=3.1416;
	float divisiones = (PI/n);
	float posicion = PI/2;
        Vertices.clear();
	Vertices.resize(n+1);
	Vertices[0] = _vertex3f(0,1,0);
	posicion -= divisiones;
	
	for(int i=1; i<n; i++){
		Vertices[i] = _vertex3f(cos(posicion), sin(posicion), 0);
		posicion -= divisiones;
	}
	
	Vertices[n] = _vertex3f(0,-1,0);
	
	generarBarrido(n,0);

	
}
	
