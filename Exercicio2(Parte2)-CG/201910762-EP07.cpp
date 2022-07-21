#include <windows.h>
#include "GL/glut.h"
#include <stdio.h>

void desenhaCasa()
{
  // Parede vermelha
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glVertex3f(0.2f, 0.3f, 0.0f);
  glVertex3f(0.4f, 0.2f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.0f);
  glEnd();

  // Parede azul
  glBegin(GL_QUADS);
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glVertex3f(0.0f, 0.2f, 0.4f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glEnd();

  // Telhado verde
  glBegin(GL_QUAD_STRIP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.4f);
  glVertex3f(0.2f, 0.3f, 0.0f);
  glVertex3f(0.2f, 0.3f, 0.4f);
  glVertex3f(0.4f, 0.2f, 0.0f);
  glVertex3f(0.4f, 0.2f, 0.4f);
  glEnd();

  // Parede amarela
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 1.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glVertex3f(0.0f, 0.2f, 0.4f);
  glVertex3f(0.2f, 0.3f, 0.4f);
  glVertex3f(0.4f, 0.2f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glEnd();

  // Porta opaca
  glBegin(GL_POLYGON);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.2f, 0.0f, 0.41f);
  glVertex3f(0.3f, 0.0f, 0.41f);
  glVertex3f(0.3f, 0.15f, 0.41f);
  glVertex3f(0.2f, 0.15f, 0.41f);
  glEnd();

  // 4 polígonos para formar 1 só com um buraco (janela) no meio
  // Polígono direito da janela
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 0.0f, 1.0f);
  glVertex3f(0.4f, 0.0f, 0.0f);
  glVertex3f(0.4f, 0.2f, 0.0f);
  glVertex3f(0.4f, 0.2f, 0.15f);
  glVertex3f(0.4f, 0.0f, 0.15f);
  glEnd();

  // Polígono abaixo da janela
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 0.0f, 1.0f);
  glVertex3f(0.4f, 0.0f, 0.15f);
  glVertex3f(0.4f, 0.1f, 0.15f);
  glVertex3f(0.4f, 0.1f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glEnd();

  // Polígono acima da janela
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 0.0f, 1.0f);
  glVertex3f(0.4f, 0.15f, 0.15f);
  glVertex3f(0.4f, 0.2f, 0.15f);
  glVertex3f(0.4f, 0.2f, 0.4f);
  glVertex3f(0.4f, 0.15f, 0.4f);
  glEnd();

  // Polígono esquerdo da janela
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 0.0f, 1.0f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.2f);
  glVertex3f(0.4f, 0.2f, 0.2f);
  glVertex3f(0.4f, 0.2f, 0.4f);
  glEnd();
}

GLfloat horzangle = -45.0, vertangle = 30.0, distance = -3.0;
bool buffer;
bool back = false;

void RenderScene(void)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, distance);
  glTranslatef(0.0f, 0.0f, -3.0f);
  glRotatef(vertangle, 1.0f, 0.0f, 0.0f);
  glRotatef(horzangle, 0.0f, 1.0f, 0.0f);
  if (!back)
  {
    glDisable(GL_CULL_FACE);

    glEnable(GL_DEPTH_TEST);
  }
  if (back)
  {
    glDisable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
  }
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /* //Linhas dos eixos X, Y e Z
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
  glEnd(); */

  desenhaCasa();

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

void LeftKey(void)
{
  horzangle -= 10;
  RenderScene();
}

void RightKey(void)
{
  horzangle += 10;
  RenderScene();
}

void UpKey(void)
{
  vertangle -= 10;
  RenderScene();
}

void DownKey(void)
{
  vertangle += 10;
  RenderScene();
}

void MouseOptions(int button, int state, int x, int y)
{
  printf("%d\n", button);
  if (button == GLUT_LEFT_BUTTON)
  {
    if (state == GLUT_UP)
    {
      LeftKey();
    }
  }

  if (button == GLUT_RIGHT_BUTTON)
  {
    if (state == GLUT_UP)
    {
      RightKey();
    }
  }
  glutPostRedisplay();
}

void KeyboardOptions(int key, int x, int y)
{
  printf("%d\n", key);
  switch (key)
  {
  case GLUT_KEY_UP:
    UpKey();
    break;
  case GLUT_KEY_DOWN:
    DownKey();
    break;
  case GLUT_KEY_LEFT:
    LeftKey();
    break;
  case GLUT_KEY_RIGHT:
    RightKey();
    break;
  }
  glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 'l':
    // buffer = true;
    back = false;
    break;
  case 'k':
    // buffer = false;
    back = true;
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
  glutCreateWindow("EP02-Q02");
  glutReshapeFunc(ChangeSize);
  glutMouseFunc(MouseOptions);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(KeyboardOptions);
  glutDisplayFunc(RenderScene);
  glutMainLoop();

  return 0;
}