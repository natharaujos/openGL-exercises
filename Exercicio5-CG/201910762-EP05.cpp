#include "windows.h"
#include "GL/glut.h"
#include <stdio.h>
#include <unistd.h>

int x1, x2, y1, y2;

void draw_pixel(int x, int y)
{
  glPointSize(6);
  glBegin(GL_POINTS);
  glColor3f(0.5, 0.0, 0.0);
  glVertex2i(x - 1, y);

  glColor3f(1.0, 0.0, 0.0);
  glVertex2i(x, y);

  glColor3f(0.3, 0.0, 0.0);
  glVertex2i(x + 1, y);
  glEnd();
}

void draw_line(int x1, int x2, int y1, int y2)
{
  int dx, dy, i, e;
  int incx, incy, inc1, inc2;
  int x, y;

  dx = x2 - x1;
  dy = y2 - y1;

  if (dx < 0)
    dx = -dx;
  if (dy < 0)
    dy = -dy;
  incx = 1;
  if (x2 < x1)
    incx = -1;
  incy = 1;
  if (y2 < y1)
    incy = -1;
  x = x1;
  y = y1;
  if (dx > dy)
  {
    draw_pixel(x, y);
    e = 2 * dy - dx;
    inc1 = 2 * (dy - dx);
    inc2 = 2 * dy;
    for (i = 0; i < dx; i++)
    {
      if (e >= 0)
      {
        y += incy;
        e += inc1;
      }
      else
        e += inc2;
      x += incx;
      draw_pixel(x, y);
    }
  }
  else
  {
    draw_pixel(x, y);
    e = 2 * dx - dy;
    inc1 = 2 * (dx - dy);
    inc2 = 2 * dx;
    for (i = 0; i < dy; i++)
    {
      if (e >= 0)
      {
        x += incx;
        e += inc1;
      }
      else
        e += inc2;
      y += incy;
      draw_pixel(x, y);
    }
  }
}

int getnumeroRandom()
{
  return rand() % 500 + 1;
}

void myDisplay()
{
  x1 = 100; // getnumeroRandom();
  x2 = 400; // etnumeroRandom();
  y1 = 100; // getnumeroRandom();
  y2 = 400; // getnumeroRandom();
  draw_line(x1, x2, y1, y2);
  usleep(500000);
  glFlush();
}

void myInit()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv)
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Atividade 4 - Parte 2");
  myInit();
  glutDisplayFunc(myDisplay);
  glutMainLoop();

  return 0;
}