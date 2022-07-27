#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

GLdouble eqn[4] = {0.0, 1.0, 0.0, 0.0};
GLdouble eqn2[4] = {1.0, 0.0, 0.0, 0.0};
GLint y = 0;
bool reshapeIcosahedron = false;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -5.0);

    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutWireIcosahedron();
    glPopMatrix();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport((GLdouble)0, (GLint)y, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    // glViewport((GLdouble)0, (GLint)-250, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_MODELVIEW);
}

void recorte(void)
{
    glClipPlane(GL_CLIP_PLANE4, eqn);
    glEnable(GL_CLIP_PLANE4);
    y = -250;
    reshapeIcosahedron = true;
    display();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'r':
        recorte();
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}