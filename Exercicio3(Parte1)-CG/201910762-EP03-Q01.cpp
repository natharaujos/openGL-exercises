#include <windows.h>
#include "GL/glut.h"
#include <stdio.h>
GLfloat distance = -3.0;
GLfloat transCone = 1.0, transCone2 = 1.0, transCone3 = 1.0;
void RenderScene(void)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, distance);
  glTranslatef(0.0f, 0.0f, -3.0f);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  // Linhas dos eixos X, Y e Z
  glPushMatrix();
  glTranslatef(-1.0, 0.0, distance);
  glColor4f(1.0, 0.5, 0.0, transCone);
  glutSolidCone(0.6, 0.6, 50, 50);
  glPopMatrix();
  glPushMatrix();
  glColor4f(0.5, 1.0, 0.0, transCone2);
  glutSolidCone(0.6, 0.6, 50, 50);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(1.0, -0.2, distance);
  glColor4f(0.0, 0.5, 1.0, transCone3);
  glutSolidCone(0.6, 0.6, 50, 50);
  glFlush();
  glutSwapBuffers();
}

void ChangeSize(GLsizei width, GLsizei height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30.0, width / height, 1.0, 10.0);
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 't':
    transCone -= 0.1;
    break;
  case 'r':
    transCone2 -= 0.1;
    break;
  case 'a':
    transCone3 -= 0.1;
    break;
  case 'T':
    transCone = 1.0;
    break;
  case 'R':
    transCone2 = 1.0;
    break;
  case 'A':
    transCone3 = 1.0;
    break;
  default:
    break;
  }
  glutPostRedisplay();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
  glutInitWindowSize(520, 520);
  glutInitWindowPosition(700, 280);
  glutCreateWindow("Atividade 3 - Parte 1");
  glutReshapeFunc(ChangeSize);
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(RenderScene);
  glutMainLoop();
}