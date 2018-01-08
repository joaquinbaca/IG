#include <modelo_3D.h>



modelo_3D::modelo_3D(){

 
}


void modelo_3D::drawPoints(){
  
  glEnableClientState( GL_VERTEX_ARRAY );
  glEnableClientState(GL_NORMAL_ARRAY);
  glColor3f(0,0,1);
  glVertexPointer( 3, GL_FLOAT, 0,&(Vertices[0]) );
  glNormalPointer(GL_FLOAT,0,&(normalesVertices[0]));
  glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
  glDrawElements( GL_TRIANGLES, 3*Triangles.size(),GL_UNSIGNED_INT,&(Triangles[0]));
}

void modelo_3D::drawLines(){
 
  glEnableClientState( GL_VERTEX_ARRAY );
  glEnableClientState(GL_NORMAL_ARRAY);
  glColor3f(0,0,1);
  glVertexPointer( 3, GL_FLOAT, 0,&(Vertices[0]) );
  glNormalPointer(GL_FLOAT,0,&(normalesVertices[0]));
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  glDrawElements( GL_TRIANGLES, 3*Triangles.size(),GL_UNSIGNED_INT,&(Triangles[0]));

}


void modelo_3D::drawSolid(){
  
  glEnableClientState( GL_VERTEX_ARRAY );
  glEnableClientState(GL_NORMAL_ARRAY);
  glColor3f(1,0,1);
  glVertexPointer( 3, GL_FLOAT, 0,&(Vertices[0]) );
  glNormalPointer(GL_FLOAT,0,&(normalesVertices[0]));
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  glDrawElements( GL_TRIANGLES, 3*Triangles.size(),GL_UNSIGNED_INT,&(Triangles[0]));

}

void modelo_3D::drawChess(){

  std::vector <_vertex3i> pares, impares;

  for(int i=0; i < Triangles.size(); i+=2)
    pares.push_back(Triangles.at(i));

  for(int i=1; i < Triangles.size(); i+=2)
    impares.push_back(Triangles.at(i)); 


  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,&(Vertices[0]));
  glColor3f(1.0,0.0,0.0);
  glDrawElements(GL_TRIANGLES,3*pares.size(),GL_UNSIGNED_INT,&(pares[0]));
  glColor3f(0.0,1.0,0.0);
  glDrawElements(GL_TRIANGLES,3*impares.size(),GL_UNSIGNED_INT,&(impares[0]));

}



_vertex3f modelo_3D::GirarEY(_vertex3f p,float angulo){

  _vertex3f a;
  a.x = cos(angulo)*p.x + sin(angulo)*p.z;
  a.y = p.y;
  a.z = -sin(angulo)*p.x +cos(angulo)*p.z;
return a;

}

void modelo_3D::tapas(int n){
  vector<_vertex3f> aux_V(Vertices.size());

  switch(n){
    case 1://quitar tapa de arriba
      if(Vertices[0].x==0){
        for(int i=0; i<Vertices.size(); i++){
          aux_V[i]=Vertices[i+1];
        }
      }
      Vertices=aux_V;
    break;
    case 2://quitar tapa de abajo
      if(Vertices[Vertices.size()-1].x==0){
        for(int i=0; i<Vertices.size()-1; i++){
          aux_V[i]=Vertices[i];
        }
      }
      Vertices=aux_V;
    break;
    case 3://quitar todas las tapas
       if((Vertices[0].x==0)&&(Vertices[Vertices.size()-1].x==0)){
         for(int i=0; i<Vertices.size()-2; i++){
          aux_V[i]=Vertices[i+1];
        }
       }
       Vertices=aux_V;
    break;
    case 4://poner tapa de arriba
        if(!Vertices[0].x==0){
           _vertex3f a;
           a.x=0;
           a.y=Vertices[0].y;
           a.z=Vertices[0].z;
          aux_V[0]=a;
        for(int i=0; i<Vertices.size(); i++){
          aux_V[i+1]=Vertices[i];
        }
      }
      Vertices=aux_V;
    break;
    case 5:

    break;
  }
  calcularNormalesCaras();
calcularNormalesVertices();


}

void modelo_3D::generarBarrido(int n,int tapa){
   
    float PI=3.1416;
    float angulo = (2*PI)/n;    
     
    bool superior = false; 
    bool inferior = false; 
    //tapas(tapa);
    if(tapa==1){
      vector<_vertex3f> aux_t(Vertices.size());
    for(int i=1; i<Vertices.size(); i++){
          aux_t[i-1]=Vertices[i];
        }
      Vertices.resize(aux_t.size()-1);
      Vertices=aux_t;
     }
   if(tapa==2){
    vector<_vertex3f> aux_t(Vertices.size()-1);
    for(int i=0; i<Vertices.size()-1; i++){
          aux_t[i]=Vertices[i];
        }
      Vertices.resize(aux_t.size());
      Vertices=aux_t;
   }
   if(tapa==3){
    vector<_vertex3f> aux_t(Vertices.size()-2);
    for(int i=0; i<Vertices.size()-2; i++){
          aux_t[i]=Vertices[i+1];
        }
       Vertices.resize(aux_t.size());
       Vertices=aux_t;
   }
    if(tapa==4){
      vector<_vertex3f> aux_t(Vertices.size()+1);
           _vertex3f a;
           a.x=0;
           a.y=Vertices[0].y;
           a.z=Vertices[0].z;
           aux_t[0]=a;
        for(int i=0; i<Vertices.size(); i++){
          aux_t[i+1]=Vertices[i];
        }
        Vertices.resize(aux_t.size());
        Vertices=aux_t;

      }
      if(tapa==5){
           _vertex3f a;
           a.x=0;
           a.y=Vertices[Vertices.size()-1].y;
           a.z=Vertices[Vertices.size()-1].z;
           Vertices.push_back(a);
      }
      if(tapa==6){
        vector<_vertex3f> aux_t(Vertices.size()+1);
           _vertex3f a;
           a.x=0;
           a.y=Vertices[0].y;
           a.z=Vertices[0].z;
           aux_t[0]=a;
        for(int i=0; i<Vertices.size(); i++){
          aux_t[i+1]=Vertices[i];
        }
        Vertices.resize(aux_t.size());
        Vertices=aux_t;
        _vertex3f b;
           b.x=0;
           b.y=Vertices[Vertices.size()-1].y;
           b.z=Vertices[Vertices.size()-1].z;
           Vertices.push_back(b);
      }

      int V_i = Vertices.size();
  
    if(Vertices[0].x==0){ 
  superior = true;
        V_i--;
      }             

    if(Vertices[Vertices.size()-1].x==0){
        inferior = true;
         V_i--; 
      } 

    int puntos = V_i*n;            
    int puntos_I = V_i*n; 
    int n_triangulos = 2*n*(V_i-1); 

    if(superior){
        puntos++;
        n_triangulos+=n;
      }  

    if(inferior){ 
       puntos++;
       n_triangulos+=n;
      }   

    vector<_vertex3f> aux_V(puntos);
    Triangles.resize(n_triangulos);

    int posicion_T;     
    int posicion_F; 
    int k = 0; 

    //Generación de puntos

    if (superior && inferior) {
     
        for(int i=0; i<Vertices.size()-2; i++) {
            aux_V[i] = Vertices[i+1];
        }
      
        for(int i=1; i<n; i++) {
            for(int j=0; j<Vertices.size()-1; j++) {
                aux_V[i*V_i+j]=GirarEY(Vertices[j+1],angulo*i);     
            }
        }
      
        aux_V[puntos-2] = Vertices[0];               
        aux_V[puntos-1] = Vertices[Vertices.size()-1]; 
    }

    if(!superior && !inferior){
        for(int i=0; i<Vertices.size(); i++) {   
            aux_V[i] = Vertices[i];
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<V_i; j++) {
                aux_V[i*V_i+j]=GirarEY(Vertices[j],angulo*i);        
    }
        }
  }
      if(superior && !inferior) {
        
        for(int i=0; i<Vertices.size()-1; i++) { 
            aux_V[i] = Vertices[i+1];
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<Vertices.size(); j++) {
                aux_V[i*V_i+j]=GirarEY(Vertices[j+1],angulo*i);       
            }
        }
        
        aux_V[puntos-1] = Vertices[0];  
    }
   
     if(!superior && inferior) {
       
        for(int i=0; i<Vertices.size()-1; i++) { 
            aux_V[i] = Vertices[i];
        }
       
        for(int i=1; i<n; i++) {
            for(int j=0; j<Vertices.size()-1; j++) {
                aux_V[i*V_i+j]=GirarEY(Vertices[j],angulo*i);     
            }
        }
   
        aux_V[puntos-1] = Vertices[Vertices.size()-1]; 
    }
  
  
    Vertices = aux_V;

   //Generación de triangulos
   

   for(int i=0; i<(V_i-1); i++) {
        for(int j=0; j<n; j++) {
            posicion_T = V_i*j+i;   
           
            Triangles[k]._0 = (posicion_T+1)%puntos_I;   
            Triangles[k]._1 = (posicion_T+V_i)%puntos_I;  
            Triangles[k]._2 = (posicion_T)%puntos_I;     
            Triangles[k+1]._0 = (posicion_T+1)%puntos_I;   
            Triangles[k+1]._1 = (posicion_T+V_i+1)%puntos_I;  
            Triangles[k+1]._2 = (posicion_T+V_i)%puntos_I;  
            k+=2; 
        }
    }

     if(inferior) { 
        posicion_F = puntos-1;
        for(int i=0; i<n; i++) {
            posicion_T = i*V_i+V_i-1;  
            Triangles[k]._0 = posicion_F;                   
            Triangles[k]._1 = (posicion_T+V_i)%puntos_I;  
            Triangles[k]._2 = (posicion_T)%puntos_I;
            k++; 
        }
    }

    if(superior) { 
        if(inferior){
           posicion_F = puntos-2;
       }else 
           posicion_F = puntos-1;    
        for(int i=0; i<n; i++) {
            posicion_T = i*V_i; 
            Triangles[k]._0 = (posicion_T)%puntos_I;    
            Triangles[k]._1 = (posicion_T+V_i)%puntos_I;  
            Triangles[k]._2 = posicion_F;                    
            k++; 
        }
    }
  

   
   
calcularNormalesCaras();
calcularNormalesVertices();

}

void modelo_3D::drawModo(int modo){

   switch (modo)
  {
    case 1: 
        drawPoints();
        break;

    case 2:
        drawLines();
      break;

    case 3: 
        drawChess();
      break;

    case 4: 
        drawSolid();
      break;

    case 5: 
        drawSolid();
        drawChess();
        drawLines();
        drawPoints();
      break;

  }

}



void modelo_3D::setAmbiental(const _vertex4f &a) {
    Mat.setAmbiental(a);
}

void modelo_3D::setDifusa(const _vertex4f &d) {
    Mat.setDifusa(d);
}

void modelo_3D::setEspecular(const _vertex4f &e) {
    Mat.setEspecular(e);
}

void modelo_3D::setBrillo(const GLfloat &b) {
    Mat.setBrillo(b);
}

void modelo_3D::activarM() {
    Mat.activarMaterial();
}

void modelo_3D::calcularNormalesCaras(){

    for(int i=0; i<Triangles.size(); i++){

      _vertex3f a = Vertices[Triangles[i]._0];
      _vertex3f b = Vertices[Triangles[i]._1];
      _vertex3f c = Vertices[Triangles[i]._2];
      _vertex3f ba, ac;
      ba.x = b.x - a.x;
      ba.y = b.y - a.y;
      ba.z = b.z - a.z;
      ac.x = a.x - c.x;
      ac.y = a.y - c.y;
      ac.z = a.z - c.z;

      _vertex3f normal;
      normal.x = ((ba.z*ac.y) - (ba.y*ac.z));
      normal.y = ((ba.x*ac.z) - (ba.z*ac.x));
      normal.z = ((ba.y*ac.x) - (ba.x*ac.y));

      float mod = sqrt((normal.x*normal.x)+(normal.y*normal.y)+(normal.z*normal.z));

      mod = 1.0/mod;

      normal.x *= mod;
      normal.y *= mod;
      normal.z *= mod;

      normalesCaras.push_back(normal);
    }

}

void modelo_3D::calcularNormalesVertices(){
   
   for(int i=0; i<Vertices.size(); i++){

        _vertex3f aux(0,0,0);

        for(int j=0; j<Triangles.size(); j++){

            if( Triangles[j]._0==i || Triangles[j]._1==i || Triangles[j]._2==i){

                aux.x += normalesCaras[j].x;
                aux.y += normalesCaras[j].y;
                aux.z += normalesCaras[j].z;
            }
        }

        double mod = sqrt((aux.x*aux.x)+(aux.y*aux.y)+(aux.z*aux.z));

        normalesVertices.push_back(_vertex3f(aux.x/mod,aux.y/mod,aux.z/mod));
   }

}