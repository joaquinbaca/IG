#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include <vector>
#include <vertex.h>
#include "CImg.h"
using namespace cimg_library;


Escena::Escena(){

    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
    nBarrido = 50;
    esferaCargada=false;
    tapas=0;
    rotar=1;
    Tl=1;
    modo=1;
    es=0;
    velocidad=0;
    angulo=0;
    luzActiva=false;

    luz1.setNombre(GL_LIGHT0);
    luz1.setDireccional(true);
    luz1.setPosicion(_vertex3f(0,0,0));
    luz1.setAmbiental(_vertex4f(0.3,0.1,0.1,1));
    luz1.setDifuso(_vertex4f(0.7,0.2,0.2,1));
    luz1.setEspecular(_vertex4f(1,0.2,0.2,1));
 

    luz2.setNombre(GL_LIGHT1);
    luz2.setDireccional(false);
    luz2.setPosicion(_vertex3f(0,0,5));
    luz2.setAmbiental(_vertex4f(0.5,0.5,0.5,1));
    luz2.setDifuso(_vertex4f(0.8,0.8,0.8,1));
    luz2.setEspecular(_vertex4f(0.9,0.9,0.9,1));


}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer
	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);


}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {



	//glEnable(GL_CULL_FACE);
switch (tecla)
	{
		case 1: 	      
		      m3D.drawLines();
			modo=2;
		      if(es==10){
		    	regulador.draw_f(Tl,rotar,modo);
		   	 }
		      break;
		case 2:		  
			  m3D.drawSolid();
			modo=4;
			if(es==10){
		    	regulador.draw_f(Tl,rotar,modo);
		   	 }
			break;
		case 3: 
			m3D.drawChess();
			modo=3;
			if(es==10){
		    	regulador.draw_f(Tl,rotar,modo);
		   	 }
			break;
		case 4: 		
             		m3D.drawPoints();
			modo=1;
            		if(es==10){
		    	regulador.draw_f(Tl,rotar,modo);
		    	}
			break;
       		 case 5: 
               		 m3D.drawPoints();
                	m3D.drawLines();
                	m3D.drawSolid();
			modo=5;
            		if(es==10){
		    	regulador.draw_f(Tl,rotar,modo);
		    	}
		
			break;
		case 6: 
			auxB=m3D;
			if(!esferaCargada){
			   m3D.generarBarrido(nBarrido,tapas);
		    }
		    
			break;
		case 7: 
			   regulador.draw_f(Tl,rotar,modo);
             		   es = 10;
             
			break;
		
            	case 8: 
           		 if(Tl>1){
            		Tl=Tl-0.05;}
			    regulador.draw_f(Tl,rotar,modo);

			break;

        	case 9: 
           		 if(Tl<5.2){
            		Tl=Tl+0.05;}
			  regulador.draw_f(Tl,rotar,modo);

			break;
			case 10:
			   luz1.activar();
			   luz2.desactivar();
                           luzActiva=true;
			break;
			case 11:
			glMatrixMode(GL_MODELVIEW);
    			glPushMatrix();
    			m3D.setAmbiental(_vertex4f(0.2,0.2,0.2,1));
    			m3D.setDifusa(_vertex4f(0.4,0.4,0.4,1));
    			m3D.setEspecular(_vertex4f(0.8,0.8,0.8,1));
    			m3D.setBrillo(10);
    			m3D.activarM();
    			glPopMatrix();
      			break;
			case 12:
			   luz2.activar();
			   luz1.desactivar();
                           luzActiva=false;
			break;
                        case 13:
			glMatrixMode(GL_MODELVIEW);
    			glPushMatrix();
    			m3D.setAmbiental(_vertex4f(0.6,0.6,0.5,1));
    			m3D.setDifusa(_vertex4f(0.6,0.6,0.5,1));
    			m3D.setEspecular(_vertex4f(0.1,0.1,0.1,1));
    			m3D.setBrillo(20);
    			m3D.activarM();
    			glPopMatrix();
			break;
			case 14:
                textura.activar();
            break;

		
	}
}

void Escena::girar_watt(){
     if(es==10){
     rotar = rotar+ (6-Tl)-velocidad;
     regulador.draw_f(Tl,rotar,modo);
     }
     if(luzActiva){
       glMatrixMode(GL_MODELVIEW);
       glPushMatrix();
       angulo += 0.1;
       luz1.setPosicion(_vertex3f(-sin(angulo*3.1617/180),cos(angulo*3.1617/180),0));
       luz1.activar();
        glPopMatrix();
     }
     
}

void Escena::dibujar() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "Tecla" << Tecla1<< std::endl;
	if (toupper(Tecla1)=='P') tecla=4;//puntos
	if (toupper(Tecla1)=='A') tecla=1;//aristas
	if (toupper(Tecla1)=='S') tecla=2;//solido
    if (toupper(Tecla1)=='C') tecla=3;//chess
	if (toupper(Tecla1)=='T') tecla=5;//todo
	if (toupper(Tecla1)=='B') tecla=6;//Barrido
	if (toupper(Tecla1)=='+') {
		if(es==10){
			
		 velocidad=velocidad-0.1;
		}else{
			/*m3D = auxB;
			nBarrido++;
			if(!esferaCargada){
      	  		 m3D.generarBarrido(nBarrido,tapas);
        		}else{
           		esfera.Redimensionar(nBarrido);
           		m3D=esfera;
       		}	}*/}
		 glMatrixMode(GL_MODELVIEW);
       		glPushMatrix();
      		 angulo += 20;
       		luz2.setPosicion(_vertex3f(-sin(angulo*3.1617/180),cos(angulo*3.1617/180),0));
       		luz2.activar();
        	glPopMatrix();
		
	}
    if (toupper(Tecla1)=='-') {
		if(es==10){
			if(((6-Tl)-velocidad)>=4.5)
			velocidad=velocidad+0.1;
		}else{
    			/*m3D = auxB;
    			if(nBarrido>3) nBarrido--;
    			if(!esferaCargada){
      	  		 m3D.generarBarrido(nBarrido,tapas);
        		}else{
          		 esfera.Redimensionar(nBarrido);
          		 m3D=esfera;
       			 }}*/}
		glMatrixMode(GL_MODELVIEW);
       		glPushMatrix();
      		 angulo -= 20;
       		luz2.setPosicion(_vertex3f(-sin(angulo*3.1617/180),cos(angulo*3.1617/180),0));
       		luz2.activar();
        	glPopMatrix();
    }
	if (toupper(Tecla1)=='W'){
                es=10;
		tecla=7;}
	if (toupper(Tecla1)=='K')
		tecla=8;
	if (toupper(Tecla1)=='L')
		tecla=9;
	if(toupper(Tecla1)=='I')
		tecla=10;
	if(toupper(Tecla1)=='M')
		tecla=11;
	if(toupper(Tecla1)=='O')
		tecla=12;
	if(toupper(Tecla1)=='N')
		tecla=13;
	if(toupper(Tecla1)=='T')
		tecla=14;
	if(toupper(Tecla1)=='1')
		camara.setOrtho();
	if(toupper(Tecla1)=='2')
		camara.setPerspectiva();
	if (toupper(Tecla1)=='Q') return 1;
	else return 0;
	
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	case GLUT_KEY_F1:m3D=cubo;esferaCargada=false;es=0;break;
	case GLUT_KEY_F2:m3D=regulador;auxB=m3D;es=10;esferaCargada=false;break;
	case GLUT_KEY_F3:
		int tapas;
		cout << "\n Introduce: \n 1=quitar tapa superior \n 2=quitar tapa inferior \n 3=quitar tapas \n 4=poner tapa superior \n 5=poner tapa inferior \n 6=poner tapas \n";
		cin >> tapas;
		switch(tapas){
			case 1:tapas=1;m3D = auxB;m3D.generarBarrido(nBarrido,tapas);break;
			case 2:tapas=2;m3D = auxB;m3D.generarBarrido(nBarrido,tapas);break;
			case 3:tapas=3;m3D = auxB;m3D.generarBarrido(nBarrido,tapas);break;
			case 4:tapas=4;m3D = auxB;m3D.generarBarrido(nBarrido,tapas);break;
			case 5:tapas=5;m3D = auxB;m3D.generarBarrido(nBarrido,tapas);break;
			case 6:tapas=6;m3D = auxB;m3D.generarBarrido(nBarrido,tapas);break;
		}

	break;
	case GLUT_KEY_F4:
		es=0;
		int forma;
		cout << "\n Introduce: \n 1=Cilindro \n 2=Vaso \n 3=tubo \n 4=vaso_i \n 5=Cono \n 6=esfera \n";
		cin >> forma;
		switch(forma){
			case 1:m3D=cilindro;esferaCargada=false;break;
			case 2:m3D=vaso;esferaCargada=false;break;
			case 3:m3D=tubo;esferaCargada=false;break;
			case 4:m3D=vaso_i;esferaCargada=false;break;
			case 5:m3D=cono;esferaCargada=false;break;
			case 6:
				esfera.Redimensionar(nBarrido);
				m3D=esfera;
				esferaCargada=true;
			break;
		}
  	break;
	case GLUT_KEY_F5:
    	char * nombre = new char[256];
	    cout << "\n Introduce el nombre del archivo: \n " << endl;
	    cin.getline(nombre,256);	
        modeloPly.open(nombre);
        modeloPly.read(modeloPly.Vertices,modeloPly.Triangles);
        m3D=modeloPly;
        delete [] nombre;
        esferaCargada=false;
        es=0;
    break;
	}
	
	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane*40,Back_plane/40);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
camara.actualizar(Width,Height,Front_plane*40,Back_plane/40);
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}




