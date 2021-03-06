// uas_kgv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <string.h>

#include <glut.h>
#include <freeglut_ext.h>
#include "table.h"
#include "window.h"
#include "snowman.h"
#include "shelf.h"
#include "fan.h"
#include "cupboard.h"
#include "chair.h"


#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define PI 3.1415926535

using namespace std;

// angle of rotation for the camera direction
float angle = 0.0, yAngle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = -5.0f, z = 18.0f;
float roll = 0.0f;

//for mouse movements
float halfWidth = (float)(WINDOW_WIDTH / 2.0);
float halfHeight = (float)(WINDOW_HEIGHT / 2.0);
float mouseX = 0.0f, mouseY = 0.0f;

//Fan
Fan f;

int n;

void angka(float jarak, float x, float y) {
	glPointSize(2);

	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);
	for (n = 0;n < 360;n += 30)
		glVertex3f(jarak * (float)sin(n * PI / 180.0) + x, jarak * (float)cos(n * PI / 180.0) + y, -9.95);
	glEnd();
}

void menit(float jarak, float x, float y) {
	glPointSize(1);

	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	for (n = 0;n < 360;n += 6)
		glVertex3f(jarak * (float)sin(n * PI / 180.0) + x, jarak * (float)cos(n * PI / 180.0) + y,-9.95);
	glEnd();
}

void panahJam() {
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0, 5.74, -9.95);
	glVertex3f(0.025, 5.79, -9.95);
	glVertex3f(0.008, 5.79, -9.95);
	glVertex3f(0.008, 6.0, -9.95);
	glVertex3f(-0.008, 6.0, -9.95);
	glVertex3f(-0.008, 5.79, -9.95);
	glVertex3f(-0.025, 5.79, -9.95);
	glVertex3f(0, 5.74, -9.95);
	glEnd();
}

void panahMenit() {
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(0, 6.10, -9.95);
	glVertex3f(0.025, 6.23, -9.95);
	glVertex3f(0.008, 6.23, -9.95);
	glVertex3f(0.008, 6.0, -9.95);
	glVertex3f(-0.008, 6.0, -9.95);
	glVertex3f(-0.008, 6.23, -9.95);
	glVertex3f(-0.025, 6.23, -9.95);
	glVertex3f(0, 6.10, -9.95);
	glEnd();
}

void panahDetik() {
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(0, 6.3, -9.95);
	glVertex3f(0.025, 6.25, -9.95);
	glVertex3f(0.008, 6.25, -9.95);
	glVertex3f(0.008, 6.0, -9.95);
	glVertex3f(-0.008, 6.0, -9.95);
	glVertex3f(-0.008, 6.25, -9.95);
	glVertex3f(-0.025, 6.25, -9.95);
	glVertex3f(0, 6.3, -9.95);
	glEnd();
}

void interactWithSnowman() {

	char str1[] = "Hello! You seem to be the only student in class today.";
	int l1 = strlen(str1); // see how many characters are in text string.
	glPushMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);

	glRasterPos3f(-9.6f, 2.7f, -2.8); // location to start printing text
	for (int i = 0; i < l1; i++) // loop until i is greater then l
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]); // Print a character on the screen
	}
	glPopMatrix();
}


void renderScene(void) {


	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	//cyrcle black clock
	glColor3f(0.1f, 0.1f, 0.1f);
	glBegin(GL_POLYGON);
	for (int i = 0;i <= 360;i++) {
		float sudut = i * (2 * PI / 360);
		float x = 0 + 0.4 * cos(sudut);
		float y = 6 + 0.4 * sin(sudut);
		glVertex3f(x, y, -10);
		glVertex3f(x, y, -9.95);
	}
	glEnd();

	angka(0.32, 0., 6.0);
	menit(0.31, 0., 6.0);
	glPopMatrix();

	glPushMatrix();
	panahDetik();
	glPopMatrix();

	glPushMatrix();
	panahMenit();
	glPopMatrix();

	glPushMatrix();
	panahJam();
	glPopMatrix();

	//cyerle white clock
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	for (int i = 0;i <= 360;i++) {
		float sudut2 = i * (2 * PI / 360);
		float x2 = 0 + 0.35 * cos(sudut2);
		float y2 = 6 + 0.35 * sin(sudut2);
		glVertex3f(x2, y2, -9.95);
	}
	glEnd();
	glFlush();

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, 2.5f, z, 
		x + lx, 2.5f + ly, z + lz,
		roll + 0.0f, 2.5f, 0.0f);

	// Draw floor
	glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();

	//wall
	glColor3f(0.8294f, 0.8216f, 0.7353f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();

	//wall
	glColor3f(0.7294f, 0.7216f, 0.6353f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glEnd();

	//wall with door
	glColor3f(0.7294f, 0.7216f, 0.6353f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(0.7294f, 0.7216f, 0.6353f);
	glBegin(GL_QUADS);
	glVertex3f(-3.0f, 0.0f, 10.0f);
	glVertex3f(-3.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(0.7294f, 0.7216f, 0.6353f);
	glBegin(GL_QUADS);
	glVertex3f(-6.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 5.0f, 10.0f);
	glVertex3f(-3.0f, 5.0f, 10.0f);
	glVertex3f(-3.0f, 7.0f, 10.0f);
	glEnd();

	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-6.0f, 5.0f, 10.01f);
	glVertex3f(-3.0f, 5.0f, 10.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-6.0f, 5.0f, 10.01f);
	glVertex3f(-6.0f, 0.0f, 10.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-3.0f, 0.0f, 10.01f);
	glVertex3f(-3.0f, 5.0f, 10.01f);
	glEnd();


	//wall
	glColor3f(0.7294f, 0.7216f, 0.6353f);
	glBegin(GL_QUADS);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	//ceiling
	glColor3f(0.95f, 0.95f, 0.95f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glEnd();

	// Draw prof's chair
	Chair profChair;
	glPushMatrix();
	glTranslatef(6.0f, 1.0f, -9.0f);
	glScalef(0.32f, 0.32f, 0.32f);
	glRotatef(-30.0, 0.0, 1.0, 0.0);
	profChair.drawChair();
	glPopMatrix();

	// Draw prof's table
	Table profTable;
	glPushMatrix();
	glTranslatef(6.0f, 1.4f, -7.6f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(-30.0, 0.0, 1.0, 0.0);
	profTable.drawTable();
	glPopMatrix();

	// Draw student chairs
	Chair studentChair[4][4];
	for (int i = -3; i <= 3; i += 2) {
		for (int j = -3; j <= 3; j += 2) {
			glPushMatrix();
			glTranslatef(i * 2.0, 0.8f, j * 2.0 + 2.2f);
			glScalef(0.25f, 0.25f, 0.25f);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			studentChair[i][j].drawChair();
			glPopMatrix();
		}
	}

	// Draw student tables
	Table studentTable[4][4];
	for (int i = -3; i <= 3; i += 2) {
		for (int j = -3; j <= 3; j += 2) {
			glPushMatrix();
			glTranslatef(i * 2.0 + 0.3f, 1.2f, j * 2.0 + 1.2f);
			glScalef(0.4f, 0.4f, 0.4f);
			// glRotatef(180.0, 0.0, 1.0, 0.0);
			studentTable[i][j].drawTable();
			glPopMatrix();
		}
	}

	// Draw cupboard
	Cupboard cupboard;
	glPushMatrix();
	glTranslatef(8.49f, 0.0f, -3.5f);
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	cupboard.drawCupboard();
	glPopMatrix();

	// Draw blackboard
	glColor3f(0.4f, 0.2f, 0.0f); 
	glBegin(GL_QUADS);
	glVertex3f(-6.0f, 2.0f, -9.99f);
	glVertex3f(-6.0f, 5.5f, -9.99f);
	glVertex3f(6.0f, 5.5f, -9.99f);
	glVertex3f(6.0f, 2.0f, -9.99f);
	glEnd();

	glColor3f(0.149f, 0.249f, 0.149f);
	glBegin(GL_QUADS);
	glVertex3f(-5.8f, 2.2f, -9.98f);
	glVertex3f(-5.8f, 5.3f, -9.98f);
	glVertex3f(5.8f, 5.3f, -9.98f);
	glVertex3f(5.8f, 2.2f, -9.98f);
	glEnd();

	//Floor pattern
	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(2.0f);
	for (int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f + i, 0.001f, -10.01f);
		glVertex3f(-10.0f + i, 0.001f, 10.01f);
		glEnd();
	}
	for (int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f, 0.001f, -10.01f + i);
		glVertex3f(10.0f, 0.001f, -10.01f + i);
		glEnd();
	}

	//windows
	Window w;
	w.drawWindow1();
	w.drawWindow2();
	w.drawWindowSill();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 8.0f);
	w.drawWindowSill();
	glPopMatrix();

	if (x < -8.0 && x > -9.0 && z < -1.0 && z > -2.0) {
		interactWithSnowman();
	}


	glPushMatrix();
	glTranslatef(0.0f, 6.0f, 0.0);
	glScalef(0.3f, 0.3f, 0.3f);
	f.drawFan();
	glPopMatrix();

	Shelf sh;
	glPushMatrix();
	glTranslatef(8.99f, 3.5f, 4.0);
	glScalef(0.25f, 0.25f, 0.25f);
	glRotatef(-90, 0.0f, 1.0f, 0.0f);
	sh.drawShelf();
	glPopMatrix();



	if (abs(mouseX) > 0.3) {
		angle -= (0.004f * mouseX);
		lx = sin(angle);
		lz = -cos(angle);
	}
	if (abs(mouseY) > 0.3) {
		if (abs(yAngle) < (M_PI / 2)) {
			yAngle += (0.002f * mouseY);
		}
		ly = sin(yAngle);
	}

	glutSwapBuffers();
}

// Handles the events triggered when one of the arrow keys are pressed.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
		break;
	case GLUT_KEY_RIGHT:
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}


// Handles the events triggered when any key on the keyboard is pressed.
//Specifically, handles w,a,s,d and Esc.
// moves the camera frward, backward and sideways.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processNormalKeys(unsigned char key, int xx, int yy) {
	float fraction = 0.1f;
	if (key == 'w') {
		x += lx * fraction;
		z += lz * fraction;
	}
	else if (key == 'a') {
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
	}
	else if (key == 's') {
		x -= lx * fraction;
		z -= lz * fraction;
	}
	else if (key == 'd') {
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
	}
	else if (key == 'x') {
		roll += 0.5f;
	}
	else if (key == 'z') {
		roll -= 0.5f;
	}

	if (key == 27)
		exit(0);
}

// Handles the events triggered when the mouse is moved in the window area. 
// Handles yaw and pitch of the camera.
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processMouseMovement(int xx, int yy) {

	mouseX = (float)(halfWidth - xx) / halfWidth;
	mouseY = (float)(halfHeight - yy) / halfHeight;
	angle -= (0.005f * mouseX);
	lx = sin(angle);
	lz = -cos(angle);

	if (abs(yAngle) < (M_PI / 2)) {
		yAngle += (0.005f * mouseY);
	}
	ly = sin(yAngle);

}

// Adjusts the viewport sie when the window size is changed and sets the projection.
// @param w : new width of window
// @param h : new height of window
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	halfWidth = (float)(w / 2.0);
	halfHeight = (float)(h / 2.0);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void animate() {

	f.rotateFan();

	/* refresh screen */
	glutPostRedisplay();
}

int main(int argc, char** argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Classroom");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(animate);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutPassiveMotionFunc(processMouseMovement);


	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
