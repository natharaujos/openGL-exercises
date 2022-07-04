#include <windows.h>
#include "GL/glut.h"
#include <iostream>

using namespace std;

// float camaMov = 0.0;
float mesaCabMov = 0.0;
float mesaEstMov = 0.0;
float bancoMov = 0.0;

float x = 0.0;
float y = 0.0;

void montarCama()
{
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(x, y, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Cama
  glColor3f(0.5, 0.5, 0.5);
  glBegin(GL_POLYGON);
  glVertex2f(-0.35, 0.9);
  glVertex2f(-0.65, 0.9);
  glVertex2f(-0.65, 0.4);
  glVertex2f(-0.35, 0.4);
  glEnd();

  // Travesseiro
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  glVertex2f(-0.4, 0.85);
  glVertex2f(-0.6, 0.85);
  glVertex2f(-0.6, 0.75);
  glVertex2f(-0.4, 0.75);
  glEnd();
  glClearColor(0, 0, 0, 0);

  glFlush();
  glLoadIdentity();
  glPopMatrix();
}

void montarMesaDeCabeceira()
{

  // Mesa de Cabeceira
  glColor3f(0.6, 0.6, 0.6);
  glBegin(GL_POLYGON);
  glVertex2f(-0.1, 0.9);
  glVertex2f(-0.3, 0.9);
  glVertex2f(-0.3, 0.75);
  glVertex2f(-0.1, 0.75);
  glEnd();

  glFlush();
}

void montarParedes()
{

  // Mesa de Cabeceira
  glColor3f(0.6, 0.6, 0.6);
  glBegin(GL_LINE_STRIP);
  glVertex2f(-0.95, 0.95);
  glVertex2f(0.95, 0.95);
  glVertex2f(0.95, -0.95);
  glVertex2f(0.75, -0.95);
  glVertex2f(0.55, -0.75);
  glEnd();
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.55, -0.95);
  glVertex2f(0.25, -0.95);
  glEnd();
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.1, -0.95);
  glVertex2f(-0.95, -0.95);
  glVertex2f(-0.95, 0.95);
  glEnd();

  glFlush();
}

void montarMesaDeEstudos()
{

  // Mesa de Estudos
  glColor3f(0.6, 0.6, 0.6);
  glBegin(GL_POLYGON);
  glVertex2f(0.5, 0.9);
  glVertex2f(0, 0.9);
  glVertex2f(0, 0.6);
  glVertex2f(0.5, 0.6);
  glEnd();

  glFlush();
}

void banco()
{

  // Banco
  glColor3f(0.6, 0.6, 0.6);
  glBegin(GL_POLYGON);
  glVertex2f(0.350, 0.45);
  glVertex2f(0.150, 0.45);
  glVertex2f(0.150, 0.55);
  glVertex2f(0.350, 0.55);
  glEnd();

  glFlush();
}

void display()
{
  // Movimenta cama
  montarCama();

  // Movimenta mesa de cabeceira
  glPushMatrix();
  glTranslatef(x, y, 0);
  montarMesaDeCabeceira();
  glPopMatrix();

  montarParedes();

  // Moviment mesa de estudos
  glPushMatrix();
  glTranslatef(x, y, 0);
  montarMesaDeEstudos();
  glPopMatrix();

  // Movimenta banco
  glPushMatrix();
  glTranslatef(x, y, 0);
  banco();
  glPopMatrix();
}

void gerenciaTeclado(unsigned char tecla, int x, int y)
{
  switch (tecla)
  {
  case 'd':
    x += 0.05;
    break;
  case 'a':
    x -= 0.05;
    break;
  case 'w':
    y += 0.05;
    break;
  case 's':
    y -= 0.05;
    break;
  default:
    break;
  }
  glutPostRedisplay();
}

void init()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("exercicio1-parte1");
  glutDisplayFunc(display);
  init();
  glutKeyboardFunc(gerenciaTeclado);
  glutMainLoop();

  return 0;
}