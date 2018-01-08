#ifndef _INC_TEXTURA_H
#define _INC_TEXTURA_H
#include <GL/glut.h>
#include <vertex.h>
#include "CImg.h"
using namespace cimg_library;
using namespace std;


class Textura{
    private:
        GLuint textura_id;
	
        
    public:
        Textura();
	void activar();
	  
	
};

#endif /* _INC_TEXTURA_H */
