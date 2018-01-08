


#ifndef _INC_CAMARA_H
#define _INC_CAMARA_H

#include <GL/glut.h>




class Camara{

	private:

		int posX;
		int posY;
		int Width;
		int Height;
		int Front_plane;
		int Back_plane;

	public:

		Camara(int x, int y);
		void activar();
		void desactivar();
		void setOrtho();
		void setPerspectiva();
		void setPosicion(int x, int y);

};

#endif /* _INC_CAMARA_H */