#include <windows.h>
#include "GL/glut.h"
#include <stdio.h>

float globalAmb[] = {0.4f, 0.4f, 0.4f, 1.0f};
float globalDif[] = {0.7, 0.7, 0.7, 1.0};
float globalEspec[] = {1.0, 1.0, 1.0, 1.0};
float posicaoLuzDifusa[4] = {-200.0, 0.0, 0.0, 1.0};
float posicaoLuzEspecular[4] = {200.0, 0.0, 0.0, 1.0};
float posicaoLuzAmbiente[4] = {0.0, 0.0, 0.0, 1.0};
float especularidade[4] = {1.0, 1.0, 1.0, 1.0};
int especMaterial = 20;

GLfloat horzangle = -45.0, vertangle = 30.0;

void init(void)
{

    glClearColor(0.0, 0.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
    glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

    glLightfv(GL_LIGHT3, GL_AMBIENT, globalAmb);
    glLightfv(GL_LIGHT3, GL_POSITION, posicaoLuzAmbiente);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, globalDif);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuzDifusa);

    glLightfv(GL_LIGHT1, GL_SPECULAR, globalEspec);
    glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuzEspecular);

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(vertangle, 1.0f, 0.0f, 0.0f);
    glRotatef(horzangle, 0.0f, 0.5f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
                1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,
                1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'a':
        glEnable(GL_LIGHT3);
        break;
    case 'A':
        glDisable(GL_LIGHT3);
        break;
    case 'e':
        glEnable(GL_LIGHT1);
        break;
    case 'E':
        glDisable(GL_LIGHT1);
        break;
    case 'd':
        glEnable(GL_LIGHT0);
        break;
    case 'D':
        glDisable(GL_LIGHT0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atividade 3 - Parte 2");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}