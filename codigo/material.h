#ifndef _INC_MATERIAL_H
#define _INC_MATERIAL_H
#include <GL/glut.h>
#include <vertex.h>



class Material{
    private:
        GLfloat brillo;
        _vertex4f ambiental;
        _vertex4f difusa;
        _vertex4f especular;
	
        
    public:
        Material();
	    void activarMaterial();
        void setAmbiental(const _vertex4f &a);
        void setDifusa(const _vertex4f &d);
        void setEspecular(const _vertex4f &e);
        void setBrillo(const GLfloat &b);
	
};

#endif /* _INC_MATERIAL_H */
