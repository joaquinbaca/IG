
#include "luz.h"

Luz::Luz() {

}

void Luz::activar() {
    //glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);

    glEnable(GL_LIGHTING);
    glEnable(nombre);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    if(direcional) {
        glRotatef(alfa,0,1,0);
        glRotatef(beta,1,0,0);
    }
    glLightfv(nombre,GL_POSITION,(GLfloat *) &posicion);
    glLightfv(nombre,GL_AMBIENT,(GLfloat *) &ambiental);
    glLightfv(nombre,GL_SPECULAR,(GLfloat *) &especular);
    glLightfv(nombre,GL_DIFFUSE,(GLfloat *) &difuso);
    glShadeModel(GL_SMOOTH);
    glPopMatrix();
   
}

void Luz::desactivar() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glDisable(nombre);
    glPopMatrix();
}

void Luz::setNombre(const GLenum &n) {
    nombre = n;
}

void Luz::setDireccional(const bool &d) {
    if(d) {
        direcional = true;
        posicion[3] = 0;
    } else {
        direcional = false;
        posicion[3] = 1;
    }
}

void Luz::setPosicion(const _vertex3f &p) {
    posicion._0 = p._0;
    posicion._1 = p._1;
    posicion._2 = p._2;
}

void Luz::setDireccion(const GLfloat &a, const GLfloat &b) {
    alfa = a;
    beta = b;
}

void Luz::setAmbiental(const _vertex4f &a) {
    ambiental = a;
}

void Luz::setDifuso(const _vertex4f &d) {
    difuso = d;
}

void Luz::setEspecular(const _vertex4f &e) {
    especular = e;
}
