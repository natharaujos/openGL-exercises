#include <GL/glut.h>
#include <stdlib.h>

int shoulder, elbow, hand, fg11, fg12, fg21, fg22 = 0;

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  // Cabeça
  glTranslatef(1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef(1.2, 1.5, 1.0);
  glutWireCube(1.0);
  glPopMatrix();

  // Corpo
  glTranslatef(-1, -3.2, 0.0);
  glTranslatef(1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef(3.0, 5, 1.0);
  glutWireCube(1.0);
  glPopMatrix();

  // Ombro
  glTranslatef(1.5, 1.5, 0.0);
  glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
  glTranslatef(1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef(2.0, 0.4, 1.0);
  glutWireCube(1.0);
  glPopMatrix();

  // Cotovelo
  glTranslatef(1.0, 0.0, 0.0);
  glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
  glTranslatef(1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef(2.0, 0.4, 1.0);
  glutWireCube(1.0);
  glPopMatrix();

  // Mão
  glTranslatef(1, 0.0, 0.0);
  glRotatef((GLfloat)hand, 0, 0, 1.0);
  glTranslatef(0.2, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.4, 0.4, 0.5);
  glutWireCube(1.0);
  glPopMatrix();

  // Dedo 1
  glPushMatrix();
  glTranslatef(0.2, 0.1, 0.0);
  glRotatef((GLfloat)fg11, 0, 0, 1.0);
  glTranslatef(0.2, 0, 0.0);
  glPushMatrix();
  glScalef(0.4, 0.1, 0.1);
  glutWireCube(1.0);
  glPopMatrix();

  // Ponta do dedo 1
  glTranslatef(0.2, 0, 0.0);
  glRotatef((GLfloat)fg12, 0, 0, 1.0);
  glTranslatef(0.2, 0, 0.0);
  glPushMatrix();
  glScalef(0.4, 0.1, 0.1);
  glutWireCube(1.0);
  glPopMatrix();

  glPopMatrix();

  // Dedo 2
  glTranslatef(0.2, -0.1, 0.0);
  glRotatef((GLfloat)fg21, 0, 0, 1.0);
  glTranslatef(0.2, 0, 0.0);
  glPushMatrix();
  glScalef(0.4, 0.1, 0.1);
  glutWireCube(1.0);
  glPopMatrix();

  // Ponta do dedo 2
  glTranslatef(0.2, 0, 0.0);
  glRotatef((GLfloat)fg22, 0, 0, 1.0);
  glTranslatef(0.2, 0, 0.0);
  glPushMatrix();
  glScalef(0.4, 0.1, 0.1);
  glutWireCube(1.0);
  glPopMatrix();

  glPopMatrix();

  glutSwapBuffers();
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(120.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 's': // Braço horário
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'S': // Braço anti-horário
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'e': // Antebraço horário
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 'E': // Antebraço anti-horário
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'q': // Mão horário
    hand = (hand - 5) % 360;
    glutPostRedisplay();
    break;
  case 'Q': // Mão anti-horário
    hand = (hand + 5) % 360;
    glutPostRedisplay();
    break;
  case 'v': // Dedo da frente horário
    fg21 = (fg21 - 5) % 360;
    glutPostRedisplay();
    break;
  case 'V': // Dedo da frente anti-horário
    fg21 = (fg21 + 5) % 360;
    glutPostRedisplay();
    break;
  case 'b': // Ponta do dedo da frente horário
    fg22 = (fg22 - 5) % 360;
    glutPostRedisplay();
    break;
  case 'B': // Ponta do dedo da frente anti-horário
    fg22 = (fg22 + 5) % 360;
    glutPostRedisplay();
    break;
  case 'f': // Dedo de trás horário
    fg11 = (fg11 - 5) % 360;
    glutPostRedisplay();
    break;
  case 'F': // Dedo de trás anti-horário
    fg11 = (fg11 + 5) % 360;
    glutPostRedisplay();
    break;
  case 'g': // Ponta do dedo da trás horário
    fg12 = (fg12 - 5) % 360;
    glutPostRedisplay();
    break;
  case 'G': // Ponta do dedo da trás anti-horário
    fg12 = (fg12 + 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(520, 520);
  glutInitWindowPosition(700, 280);
  glutCreateWindow("REO 03");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}