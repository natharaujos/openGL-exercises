#include <windows.h>
#include "GL/glut.h"
#include <iostream>

using namespace std;

// float camaMov = 0.0;
// float mesaCabMov = 0.0;
// float mesaEstMov = 0.0;
// float bancoMov = 0.0;

float eixoX = 0.0;
float eixoY = 0.0;
char opa;

void montarCama()
{
  if (opa == 'c')
  {
    glPushMatrix();
    glTranslatef(eixoX, eixoY, 0);
  }
  // Cama
  glBegin(GL_POLYGON);
  glColor3f(0.5, 0.5, 0.5);
  glVertex2f(-0.35, 0.9);
  glVertex2f(-0.65, 0.9);
  glVertex2f(-0.65, 0.4);
  glVertex2f(-0.35, 0.4);
  glEnd();

  // Travesseiro
  // glColor3f(1, 1, 1);
  // glBegin(GL_POLYGON);
  // glVertex2f(-0.4, 0.85);
  // glVertex2f(-0.6, 0.85);
  // glVertex2f(-0.6, 0.75);
  // glVertex2f(-0.4, 0.75);
  // glClearColor(0, 0, 0, 0);
  // glEnd();

  if (opa == 'c')
  {
    glPopMatrix();
  }
}

void montarMesaDeCabeceira()
{
  if (opa == 'm')
  {
    glPushMatrix();
    glTranslatef(eixoX, eixoY, 0);
  }

  // Mesa de Cabeceira
  glColor3f(0.6, 0.6, 0.6);
  glBegin(GL_POLYGON);
  glVertex2f(-0.1, 0.9);
  glVertex2f(-0.3, 0.9);
  glVertex2f(-0.3, 0.75);
  glVertex2f(-0.1, 0.75);
  glEnd();

  if (opa == 'm')
  {
    glPopMatrix();
  }

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
  if (opa == 'e')
  {
    glPushMatrix();
    glTranslatef(eixoX, eixoY, 0);
  }
  // Mesa de Estudos
  glColor3f(0.6, 0.6, 0.6);
  glBegin(GL_POLYGON);
  glVertex2f(0.5, 0.9);
  glVertex2f(0, 0.9);
  glVertex2f(0, 0.6);
  glVertex2f(0.5, 0.6);
  glEnd();

  if (opa == 'e')
  {
    glPopMatrix();
  }

  glFlush();
}

void banco()
{
  if (opa == 'b')
  {
    glPushMatrix();
    glTranslatef(eixoX, eixoY, 0);
  }
  // Banco
  glColor3f(0.6, 0.6, 0.6);
  glBegin(GL_POLYGON);
  glVertex2f(0.350, 0.45);
  glVertex2f(0.150, 0.45);
  glVertex2f(0.150, 0.55);
  glVertex2f(0.350, 0.55);
  glEnd();

  if (opa == 'b')
  {
    glPopMatrix();
  }

  glFlush();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  // Movimenta cama

  if (opa == 't')
  {
    glPushMatrix();
    glTranslatef(eixoX, eixoY, 0);
  }
  montarCama();

  // Movimenta mesa de cabeceira
  // glPushMatrix();
  // glTranslatef(x, y, 0);
  montarMesaDeCabeceira();
  // glPopMatrix();

  montarParedes();

  // Moviment mesa de estudos
  // glPushMatrix();
  // glTranslatef(x, y, 0);
  montarMesaDeEstudos();
  // glPopMatrix();

  // Movimenta banco
  // glPushMatrix();
  // glTranslatef(x, y, 0);
  banco();
  // glPopMatrix();
  if (opa == 't')
  {
    glPopMatrix();
  }
  glFlush();
}

void gerenciaTeclado(unsigned char tecla, int x, int y)
{
  switch (tecla)
  {
  case 'd':
    eixoX += 0.05;
    break;
  case 'a':
    eixoX -= 0.05;
    break;
  case 'w':
    eixoY += 0.05;
    break;
  case 's':
    eixoY -= 0.05;
    break;
  case 'c':
    opa = 'c';
    break;
  case 'm':
    opa = 'm';
    break;
  case 'e':
    opa = 'e';
    break;
  case 'b':
    opa = 'b';
    break;
  case 't':
    opa = 't';
    break;
  default:
    break;
  }
  glutPostRedisplay();
}

void init()
{
  glColor3f(1, 1, 1);
  glMatrixMode(GL_MODELVIEW);
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