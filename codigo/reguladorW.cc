#include <reguladorW.h>


///////////////esfera_mango/////////////////
esfera_Mango::esfera_Mango(){
esfera_N.Redimensionar(50);

}


void esfera_Mango::draw(int modo){
     glPushMatrix();
     glScalef(2,2,2);
     esfera_N.drawModo(modo);
     glPopMatrix();
     
}


//////////////////cilindro_superior//////////////////////

cilindro_superior::cilindro_superior(){
cilindro_N.generarBarrido(50,0);
modeloPly.open("beethoven.ply");
modeloPly.read(modeloPly.Vertices,modeloPly.Triangles);
m3D=modeloPly;
}


void cilindro_superior::draw(int modo){
     glPushMatrix();
     glTranslatef(0,5,0);
     glScalef(0.5,10,0.5);
     cilindro_N.drawModo(modo);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-1.5,4.5,0);
     glScalef(0.25,0.25,0.25);
     glRotatef(90,0,0,1);
     m3D.drawModo(modo);
     glPopMatrix();

}



//////////////////mango//////////////////////

Mango::Mango(){

}


void Mango::draw(int modo){
     glPushMatrix();
     glTranslatef(0,11,0);
     esfera_Man.draw(modo);
     glPopMatrix();
     
     glPushMatrix();
     cilindro_sup.draw(modo);
     glPopMatrix();
}

//////////////////cubo_union//////////////////////

Cubo_union::Cubo_union(){

}


void Cubo_union::draw(int modo){
     glPushMatrix();
     glScalef(1.75,1,1);
     cubo_n.drawModo(modo);
     glPopMatrix();
}

//////////////////cubo_union//////////////////////

Cubo_tope::Cubo_tope(){

}


void Cubo_tope::draw(int modo){
     glPushMatrix();
     glTranslatef(0,2,0);
     glScalef(0.25,4,0.25);
     cubo_n.drawModo(modo);
     glPopMatrix();
}

//////////////////Cilindro_anclaje//////////////////////

Cilindro_anclaje::Cilindro_anclaje(){
cilindro_N.generarBarrido(50,0);
}


void Cilindro_anclaje::draw(int modo){
     glPushMatrix();
     glTranslatef(0,2.5,0);
     glScalef(0.25,5,0.25);
     cilindro_N.drawModo(modo);
     glPopMatrix();

}


///////////////////Mano_doble//////////////////

Mano::Mano(){

}

void Mano::draw(int modo,float T){
	float angulo_a = 0.0;
    float angulo_b = 0.0;
    float b=5.012827802;
    float a = 5;
    float c= T;
    //teorema del coseno
    
    angulo_a=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*a))*(180/3.14159265);
    angulo_b=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c))*(180/3.14159265);

     glPushMatrix();
     glTranslatef(0.45,0.5,0);
     glRotatef(-180+angulo_a,0,0,1);
     mango.draw(modo);
     glPopMatrix();
   
     glPushMatrix();
     glTranslatef(0.45,0.5-c,0);
     glRotatef(5-angulo_b,0,0,1);
     cilindro_anclaje.draw(modo);
     glPopMatrix();

}

//////////////////Brazo_completo//////////////////////

Brazo_completo::Brazo_completo(){

}


void Brazo_completo::draw(float T,int modo){

	 glPushMatrix();
     glTranslatef(0,0.5,0);
     cubo_union.draw(modo);
     glPopMatrix();
 
     glPushMatrix();
     mano.draw(modo,T);
     glPopMatrix();

     glPushMatrix();
     glRotatef(180,0,1,0);
     mano.draw(modo,T);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0,0.5-T,0);
     cubo_union.draw(modo);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-0.5,-4-T,0);
     cubo_tope.draw(modo);
     glPopMatrix();
     
    
   
}

//////////////////Cilindro_cuerpo//////////////////////

Cuerpo::Cuerpo(){
cilindro_N.generarBarrido(50,0);
}


void Cuerpo::draw(int modo){
     glPushMatrix();
     glTranslatef(0,5,0);
     glScalef(0.5,10,0.5);
     cilindro_N.drawModo(modo);
     glPopMatrix();
       
     glPushMatrix();
     glTranslatef(0,0.25,0);
     glScalef(6,0.5,6);
     cubo_n.drawModo(modo);
     glPopMatrix();

}
///////regulador////////////////

reguladorW::reguladorW(){
  

}
void reguladorW::draw_f(float T,int rotar,int modo){
     glPushMatrix();
     glTranslatef(0,10,0);
     glRotatef(rotar,0,1,0);
     brazo_completo.draw(T,modo);
     glPopMatrix();
     
     glPushMatrix();
     cuerpo.draw(modo);
     glPopMatrix();
}

/////////////////////////////
