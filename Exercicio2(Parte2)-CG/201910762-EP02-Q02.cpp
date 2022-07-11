#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
GLfloat horzangle = -45.0, vertangle = 30.0, distance = -3.0;
bool pressP = false;
using namespace std;

void RenderScene(void)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, distance);
  glTranslatef(0.0f, 0.0f, -3.0f);
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.33f, 0.33f, 0.33f, 0.33f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Parede vermelha
  glBegin(GL_POLYGON);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glVertex3f(0.4f, 0.2f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.0f);
  glEnd();

  // Parede azul
  glBegin(GL_QUADS);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glVertex3f(0.0f, 0.2f, 0.4f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glEnd();

  // // Telhado verde
  glBegin(GL_POLYGON);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.4f);
  glVertex3f(0.4f, 0.2f, 0.4f);
  glVertex3f(0.4f, 0.2f, 0.0f);
  glEnd();

  // // Telhado verde
  glBegin(GL_POLYGON);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.0f);
  glEnd();

  // Parede amarela
  glBegin(GL_POLYGON);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glVertex3f(0.0f, 0.2f, 0.4f);
  glVertex3f(0.4f, 0.2f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void ChangeSize(GLsizei width, GLsizei height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, 1.0, -1.0, 1.0, 30.0);
}

void KeyboardOptions(unsigned char key, int x, int y)
{
  printf("%d\n", key);
  switch (key)
  {
  case 'p':
    if (pressP)
    {
      pressP = false;
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(60.0, 1, 1.0, 30.0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
    }
    else
    {
      pressP = true;
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-1.0, 1.0, 1.0, -1.0, 1.0, 30.0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
    }
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
  glutCreateWindow("REO 02");
  glutReshapeFunc(ChangeSize);
  glutKeyboardFunc(KeyboardOptions);
  glutDisplayFunc(RenderScene);
  glutMainLoop();

  return 0;
}