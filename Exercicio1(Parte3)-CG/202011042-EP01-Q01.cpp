#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

GLfloat horzangle = -45.0, vertangle = 30.0, distance = -3.0;

int opcao = 1;

void RenderScene(void)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, distance);
  glRotatef(vertangle, 1.0f, 0.0f, 0.0f);
  glRotatef(horzangle, 0.0f, 1.0f, 0.0f);
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.7f, 0.0f, 0.0f);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.5f, 0.0f);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.7f);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glVertex3f(0.2f, 0.3f, 0.0f);
  glVertex3f(0.4f, 0.2f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.0f);
  glEnd();
  glBegin(GL_QUADS);
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glVertex3f(0.0f, 0.2f, 0.4f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glEnd();
  glBegin(GL_QUAD_STRIP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.4f);
  glVertex3f(0.2f, 0.3f, 0.0f);
  glVertex3f(0.2f, 0.3f, 0.4f);
  glVertex3f(0.4f, 0.2f, 0.0f);
  glVertex3f(0.4f, 0.2f, 0.4f);
  glEnd();
  glColor3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_LINE_STRIP);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.0f);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glVertex3f(0.4f, 0.2f, 0.4f);
  glEnd();
  glFlush();
  glutSwapBuffers();
}

void ChangeSize(GLsizei width, GLsizei height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (opcao == 1)
  {
    gluPerspective(30.0, 1, 1, 10);
  }
  else
  {
    glOrtho(-0.7, 0.7, -0.7, 0.7, 1.0, 10.0);
  }
}

void KeyboardOptions(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 'w':
    vertangle -= 5;
    break;
  case 's':
    vertangle += 5;
    break;
  case 'a':
    horzangle -= 5;
    break;
  case 'd':
    horzangle += 5;
    break;
  case 'v':
    distance -= 0.5;
    break;
  case 'c':
    distance += 0.5;
    break;
  case 'p':
    opcao *= -1;
    ChangeSize(500, 500);
    break;
  }
  glutPostRedisplay();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("OpenGL - Mouse");
  glutReshapeFunc(ChangeSize);
  glutKeyboardFunc(KeyboardOptions);
  glutDisplayFunc(RenderScene);
  glutMainLoop();
  return 0;
}
