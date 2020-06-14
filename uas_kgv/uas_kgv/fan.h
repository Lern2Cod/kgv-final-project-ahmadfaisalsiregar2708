#ifndef FAN_H
#define FAN_H

#include <glut.h>
#include <freeglut_ext.h>
#include <math.h>

#define DEF_D 5

class Fan {
	private:
		float rotationAngle = 0.0f;

	public:
		
		void drawFan();

		void rotateFan();

};

#endif
