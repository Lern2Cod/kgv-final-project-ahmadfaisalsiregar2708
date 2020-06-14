
#include "fan.h"

void Fan::drawFan()
{
    glTranslatef(0, 5, -5.0);
    glScalef(5, 5, 5);
    //glRotatef(90, 1, 0, 0);
    //Cube
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(1.0f, 1.2f, 1.0f);
    glScalef(0.5f, 0.4f, 0.5f);
    glTranslatef(0.0f, -2.0f, 0.0f);
    glScalef(1.0f, 0.7f, 1.0f);
    glTranslatef(0.0f, -0.5f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    glTranslatef(0.0f, -1.05f, 0.0f);
    glScalef(0.15f, 0.15f, 0.15f);
    glTranslatef(0.0f, -2.2f, 0.0f);
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= 360; j += DEF_D) {
        glColor3f(0.302f, 0.149f, 0.0f);
        glVertex3f(cos(j), +1, sin(j));
        glColor3f(0.6f, 0.302f, 0.0f);
        glVertex3f(cos(j), -1, sin(j));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 1.55f);
    glScalef(0.25f, 0.25f, 0.25f);
    glutSolidTorus(0.1f, 0.72f, 25.0f, 25.0f);
    glPopMatrix();

    glPushMatrix();

    glPushMatrix();
    glColor3f(0.7294f, 0.7216f, 0.6353f);
    glTranslatef(-1.0f, -1.55f, 0.0f);
    glScalef(2.5f, 0.1f, 0.75f);
    glutSolidCube(0.5f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.55f, 0.0f);
    glScalef(0.05f, 0.11f, 0.05f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -5.0f);
    glScalef(1.0f, 1.0f, 2.4f);
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= 360; j += DEF_D) {
        glColor3f(0.3f, 0.3f, 0.3f);
        glVertex3f(cos(j), +1, sin(j));
        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex3f(cos(j), -1, sin(j));
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glPushMatrix();
    glColor3f(0.7294f, 0.7216f, 0.6353f);
    glTranslatef(-1.0f, -1.55f, 0.0f);
    glScalef(2.5f, 0.1f, 0.75f);
    glutSolidCube(0.5f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.55f, 0.0f);
    glScalef(0.05f, 0.11f, 0.05f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -5.0f);
    glScalef(1.0f, 1.0f, 2.4f);
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= 360; j += DEF_D) {
        glColor3f(0.3f, 0.3f, 0.3f);
        glVertex3f(cos(j), +1, sin(j));
        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex3f(cos(j), -1, sin(j));
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    glColor3f(0.7294f, 0.7216f, 0.6353f);
    glTranslatef(-1.0f, -1.55f, 0.0f);
    glScalef(2.5f, 0.1f, 0.75f);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.55f, 0.0f);
    glScalef(0.05f, 0.11f, 0.05f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -5.0f);
    glScalef(1.0f, 1.0f, 2.4f);
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= 360; j += DEF_D) {
        glColor3f(0.3f, 0.3f, 0.3f);
        glVertex3f(cos(j), +1, sin(j));
        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex3f(cos(j), -1, sin(j));
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotatef(270, 0, 1, 0);
    glPushMatrix();
    glColor3f(0.7294f, 0.7216f, 0.6353f);
    glTranslatef(-1.0f, -1.55f, 0.0f);
    glScalef(2.5f, 0.1f, 0.75f);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.55f, 0.0f);
    glScalef(0.05f, 0.11f, 0.05f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0, 0, -5);
    glScalef(1.0f, 1.0f, 2.4f);
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= 360; j += DEF_D) {
        glColor3f(0.3f, 0.3f, 0.3f);
        glVertex3f(cos(j), +1, sin(j));
        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex3f(cos(j), -1, sin(j));
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}

void Fan::rotateFan()
{
    rotationAngle += 1.5f;
}