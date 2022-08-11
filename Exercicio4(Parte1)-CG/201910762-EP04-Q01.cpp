#include <windows.h>
#include "GL/glut.h"
#include <stdio.h>
#include <iostream>
#include <unistd.h>

int x1 = 10, y1 = 20, x2 = 100, y2 = 50;

void myInit()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(x, y);
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
  int cont = 0;
  for (int i = 0; i < 1000000000; i++)
  {
    x1 = getnumeroRandom();
    x2 = getnumeroRandom();
    y1 = getnumeroRandom();
    y2 = getnumeroRandom();
    draw_line(x1, x2, y1, y2);
    glFlush();
    usleep(10000000000000000000000);
  }
}

int main(int argc, char **argv)
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Bresenham's Line Drawing");
  myInit();
  glutDisplayFunc(myDisplay);
  glutMainLoop();

  return 0;
}