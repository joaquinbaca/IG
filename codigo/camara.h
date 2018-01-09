


#ifndef _INC_CAMARA_H
#define _INC_CAMARA_H

#include <GL/glut.h>




class Camara{

	private:

		GLfloat posX;
		GLfloat posY;
		GLfloat Width;
		GLfloat Height;
		GLfloat Front_plane;
		GLfloat Back_plane;

	public:

		Camara();
		void actualizar(GLfloat Width, GLfloat Height, GLfloat Front_plane, GLfloat Back_plane);
		void desactivar();
		void setOrtho();
		void setPerspectiva();
		void setPosicion(int x, int y);

};

#endif /* _INC_CAMARA_H */
