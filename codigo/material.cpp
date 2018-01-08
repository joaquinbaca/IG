#include "material.h"

Material::Material(){
   
}
void Material::setBrillo(const GLfloat &b) {
    brillo = b;
}
void Material::setAmbiental(const _vertex4f &a) {
    ambiental = a;
}

void Material::setDifusa(const _vertex4f &d) {
    difusa = d;
}

void Material::setEspecular(const _vertex4f &e) {
    especular = e;
}

void Material::activarMaterial() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
   
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *) &ambiental);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *) &difusa);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *) &especular);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,brillo);
    glShadeModel(GL_SMOOTH);


    glPopMatrix();
}
