#include "GL/glut.h"
#include <iostream>
#include <cmath>
#include <windows.h>
#define PI 3.14159265359

using namespace std;

void circle(int raio, int x, int y, int min = 0, int max = 360)
{
	float theta;
	for (int i = min; i < max; i++)
	{
		theta = i * PI / (max / 2);
		glVertex2f(x + raio * cos(theta), y + raio * sin(theta));
	}
}

void arc(int quadrant, float iniX, float iniY, float radius)
{
	float theta = 0;
	float finalX, finalY = 0;
	int alphamax, alphamin;
	switch (quadrant)
	{
	case 1:
		alphamax = 90;
		alphamin = 0;
		break;
	case 2:
		alphamax = 180;
		alphamin = 90;
		break;
	case 3:
		alphamax = 270;
		alphamin = 180;
		break;
	case 4:
		alphamax = 360;
		alphamin = 270;
		break;
	}

	glBegin(GL_LINES);
	for (int i = alphamin; i < alphamax; i++)
	{
		theta = i * PI / 180;
		finalX = iniX + radius * sin(theta);
		finalY = iniY + radius * cos(theta);
		glVertex2f(finalX, finalY);
	}
	glEnd();
}

void banheira()
{
	// Circle
	glBegin(GL_POLYGON);
	circle(2.1, 120, 27);
	glEnd();

	// Rectangle
	glBegin(GL_LINE_LOOP);
	glVertex2d(10.0, 0.0);
	glVertex2d(140.0, 0.0);
	glVertex2d(140.0, 60.0);
	glVertex2d(10.0, 60.0);
	glEnd();

	// Inside rectangle with arcs
	glBegin(GL_LINE_LOOP);
	glVertex2f(25, 50);
	glVertex2f(125, 50);
	glEnd();

	arc(1, 125, 45, 5);

	glBegin(GL_LINE_LOOP);
	glVertex2f(130, 45);
	glVertex2f(130, 15);
	glEnd();

	arc(2, 125, 15, 5);

	glBegin(GL_LINE_LOOP);
	glVertex2f(125, 10);
	glVertex2f(25, 10);
	glEnd();

	arc(3, 25, 15, 5);

	glBegin(GL_LINE_LOOP);
	glVertex2f(20, 15);
	glVertex2f(20, 45);
	glEnd();

	arc(4, 25, 45, 5);
}

void chuveiro()
{
	// Outside rectangle
	glBegin(GL_LINE_LOOP);
	glVertex2d(180.0, 10.0);
	glVertex2d(250.0, 10.0);
	glVertex2d(250.0, 50.0);
	glVertex2d(180.0, 50.0);
	glEnd();

	// Inside rectangle
	glBegin(GL_LINE_LOOP);
	glVertex2d(170.0, 0.0);
	glVertex2d(260.0, 0.0);
	glVertex2d(260.0, 60.0);
	glVertex2d(170.0, 60.0);
	glEnd();

	// Circle
	glBegin(GL_POLYGON);
	circle(2.1, 215, 27);
	glEnd();

	//"X" format
	glBegin(GL_LINES);
	glVertex2d(180.0, 50.0);
	glVertex2f(210, 30);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(250.0, 50.0);
	glVertex2f(220, 30);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(180.0, 10);
	glVertex2f(210, 25);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(250.0, 10);
	glVertex2f(220, 25);
	glEnd();
}

void espelho()
{
	// Rectangle
	glBegin(GL_LINE_LOOP);
	glVertex2f(10, 100);
	glVertex2f(20, 100);
	glVertex2f(20, 160);
	glVertex2f(10, 160);
	glEnd();
}

void pia()
{
	// Outside rectangle wit arcs
	glBegin(GL_LINES);
	glVertex2f(35, 160);
	glVertex2f(70, 160);
	glEnd();

	arc(1, 70, 155, 5);

	glBegin(GL_LINES);
	glVertex2f(75, 155);
	glVertex2f(75, 105);
	glEnd();

	arc(2, 70, 105, 5);

	glBegin(GL_LINES);
	glVertex2f(70, 100);
	glVertex2f(35, 100);
	glEnd();

	arc(3, 35, 105, 5);

	glBegin(GL_LINES);
	glVertex2f(30, 105);
	glVertex2f(30, 155);
	glEnd();

	arc(4, 35, 155, 5);

	// Inside rectangle wit arcs
	glBegin(GL_LINES);
	glVertex2f(45, 150);
	glVertex2f(60, 150);
	glEnd();

	arc(1, 60, 145, 5);

	glBegin(GL_LINES);
	glVertex2f(65, 145);
	glVertex2f(65, 115);
	glEnd();

	arc(2, 60, 115, 5);

	glBegin(GL_LINES);
	glVertex2f(45, 110);
	glVertex2f(60, 110);
	glEnd();

	arc(3, 45, 115, 5);

	glBegin(GL_LINES);
	glVertex2f(40, 115);
	glVertex2f(40, 145);
	glEnd();

	arc(4, 45, 145, 5);

	// Circle
	glBegin(GL_POLYGON);
	circle(2.1, 35, 130);
	glEnd();
}

void vasoSanitario()
{
	// Six-sided polygon
	glBegin(GL_LINE_LOOP);
	glVertex2f(30, 200);
	glVertex2f(45, 200);
	glVertex2f(55, 230);
	glVertex2f(55, 235);
	glVertex2f(20, 235);
	glVertex2f(20, 230);
	glEnd();

	// Top of the polygon
	glBegin(GL_LINES);
	glVertex2f(20, 230);
	glVertex2f(55, 230);
	glEnd();
}

void armario()
{
	// Square
	glBegin(GL_LINE_LOOP);
	glVertex2f(220, 100);
	glVertex2f(260, 100);
	glVertex2f(260, 140);
	glVertex2f(220, 140);
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	banheira();
	chuveiro();
	espelho();
	pia();
	vasoSanitario();
	armario();

	glFlush();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 260, 0, 260);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(260, 260);
	glutInitWindowPosition(830, 410);
	glutCreateWindow("REO01");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}