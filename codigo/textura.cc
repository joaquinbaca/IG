#include "textura.h"
using namespace std;
Textura::Textura(){
/*
GLfloat vertices[] = {0, 0,
		      10, 0,
		      10, 5,
		      0, 5};
GLfloat texVertices[] = {0.0,1.0,
			 1.0,1.0,
			 1.0,0.0,
			 0.0,0.0};
vector<unsigned char> data;

   CImg<unsigned char> logo;
   logo.load("./logo.jpg");

   // empaquetamos bien los datos
   for (long y = 0; y < logo.height(); y ++)
      for (long x = 0; x < logo.width(); x ++)
      {
	 unsigned char *r = logo.data(x, y, 0, 0);
	 unsigned char *g = logo.data(x, y, 0, 1);
	 unsigned char *b = logo.data(x, y, 0, 2);
	 data.push_back(*r);
	 data.push_back(*g);
	 data.push_back(*b);
      }

   glGenTextures(1, &textura_id);
   glBindTexture(GL_TEXTURE_2D, textura_id);

   glActiveTexture(GL_TEXTURE0);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

   // TRASFIERE LOS DATOS A GPU
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, logo.width(), logo.height(),
		0, GL_RGB, GL_UNSIGNED_BYTE, &data[0]);

   */
}

void Textura::activar(){/*
GLfloat vertices[] = {-5, -5,

		      5, -5,
		      5, 5,
		      -5, 5};
GLfloat texVertices[] = {0.0,1.0,

			 1.0,1.0,
			 1.0,0.0,
			 0.0,0.0};
vector<unsigned char> data;

   CImg<unsigned char> logo;
   logo.load("./logo.jpg");

   // empaquetamos bien los datos
   for (long y = 0; y < logo.height(); y ++)
      for (long x = 0; x < logo.width(); x ++)
      {
	 unsigned char *r = logo.data(x, y, 0, 0);
	 unsigned char *g = logo.data(x, y, 0, 1);
	 unsigned char *b = logo.data(x, y, 0, 2);
	 data.push_back(*r);
	 data.push_back(*g);
	 data.push_back(*b);
      }

   glGenTextures(1, &textura_id);
   glBindTexture(GL_TEXTURE_2D, textura_id);

   glActiveTexture(GL_TEXTURE0);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

   // TRASFIERE LOS DATOS A GPU
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, logo.width(), logo.height(),
		0, GL_RGB, GL_UNSIGNED_BYTE, &data[0]);
   glEnable(GL_TEXTURE_2D);
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState (GL_TEXTURE_COORD_ARRAY_EXT);

   glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, textura_id);

   glVertexPointer(2, GL_FLOAT, 0, vertices);
   glTexCoordPointer(2, GL_FLOAT, 0, texVertices);

   glDrawArrays(GL_QUADS, 0, 4);

   glDisableClientState(GL_VERTEX_ARRAY);
   glBindTexture(GL_TEXTURE_2D, 0);
   glDisable(GL_TEXTURE_2D);*/
}
