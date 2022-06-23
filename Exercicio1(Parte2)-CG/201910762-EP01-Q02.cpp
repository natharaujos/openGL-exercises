  #include <windows.h>
  #include "GL/glut.h"
  #include <iostream>

  float camaMov = 0.0;
  float mesaCabMov = 0.0;
  float mesaEstMov = 0.0;
  float bancoMov = 0.0;

  void montarCama() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Cama
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.35, 0.9);
    glVertex2f(-0.65, 0.9);
    glVertex2f(-0.65, 0.4);
    glVertex2f(-0.35, 0.4);
    glEnd();

    // Travesseiro
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.85);
    glVertex2f(-0.6, 0.85);
    glVertex2f(-0.6, 0.75);
    glVertex2f(-0.4, 0.75);
    glEnd();
    glClearColor(0,0,0,0);

    glFlush();
  }

  void montarMesaDeCabeceira() {

    // Mesa de Cabeceira
    glColor3f(0.6,0.6,0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.3, 0.75);
    glVertex2f(-0.1, 0.75);
    glEnd();

    glFlush();
  }

  void montarParedes() {

    // Mesa de Cabeceira
    glColor3f(0.6,0.6,0.6);
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

  void montarMesaDeEstudos() {

    // Mesa de Estudos
    glColor3f(0.6,0.6,0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, 0.9);
    glVertex2f(0, 0.9);
    glVertex2f(0, 0.6);
    glVertex2f(0.5, 0.6);
    glEnd();

    glFlush();
  }

  void banco() {

    // Banco
    glColor3f(0.6,0.6,0.6);
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
    glPushMatrix();
    glTranslatef(camaMov, 0, 0);
    montarCama();
    glPopMatrix();

    // Movimenta mesa de cabeceira
    glPushMatrix();
    glTranslatef(mesaCabMov, 0, 0);
    montarMesaDeCabeceira();
    glPopMatrix();

    montarParedes();

    glPushMatrix();
    glTranslatef(0, mesaEstMov, 0);
    montarMesaDeEstudos();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, bancoMov, 0);
    banco();
    glPopMatrix();
  }

  void gerenciaTeclado(int tecla, int x, int y) {
    switch(tecla) {
      case GLUT_KEY_RIGHT:
        camaMov +=0.05;
        break;
      case GLUT_KEY_LEFT:
        mesaCabMov -=0.05;
        break;
      case GLUT_KEY_UP:
        mesaEstMov +=0.05;
        break;
      case GLUT_KEY_DOWN:
        bancoMov -=0.05;
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

  int main(int argc, char** argv) 
  {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("exercicio1-parte1");
    glutDisplayFunc(display);
    init();
    glutSpecialFunc(gerenciaTeclado);
    glutMainLoop();

    return 0;
  }