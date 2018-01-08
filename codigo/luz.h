#ifndef _INC_LUZ_H
#define _INC_LUZ_H

#include <GL/glut.h>
#include <vertex.h>

class Luz {
    private:
        GLenum nombre;
        GLfloat alfa;
        GLfloat beta;
        _vertex4f ambiental;
        _vertex4f difuso;
        _vertex4f especular;
        bool direcional;
        _vertex4f posicion;
    public:
        Luz();
        void activar();
        void desactivar();
        void setNombre(const GLenum &n);
        void setDireccional(const bool &d);
        void setAmbiental(const _vertex4f &a);
        void setDifuso(const _vertex4f &d);
        void setEspecular(const _vertex4f &e);
        void setPosicion(const _vertex3f &p);
        void setDireccion(const GLfloat &a, const GLfloat &b);

};

#endif /* _INC_LUZ_H */
