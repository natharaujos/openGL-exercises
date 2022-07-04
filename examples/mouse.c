#include <GL/glut.h>
  
GLfloat horzangle = -45.0,vertangle = 30.0; 
  
void RenderScene(void) { 
  glMatrixMode( GL_MODELVIEW ); 
  glLoadIdentity(); 
  glTranslatef(0.0f,0.0f,-3.0f); 
  glRotatef(vertangle,1.0f,0.0f,0.0f); 
  glRotatef(horzangle,0.0f,1.0f,0.0f); 
  glEnable( GL_DEPTH_TEST ); 
  glClearColor(0.0f,0.0f,0.0f,0.0f); 
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); 
  glBegin( GL_LINES ); 
    glColor3f(0.0f,0.0f,1.0f); 
    glVertex3f(0.0f,0.0f,0.0f); 
    glVertex3f(0.7f,0.0f,0.0f); 
    glColor3f(1.0f,0.0f,0.0f); 
    glVertex3f(0.0f,0.0f,0.0f); 
    glVertex3f(0.0f,0.5f,0.0f); 
    glColor3f(0.0f,1.0f,0.0f); 
    glVertex3f(0.0f,0.0f,0.0f); 
    glVertex3f(0.0f,0.0f,0.7f); 
  glEnd(); 
  glBegin( GL_POLYGON ); 
    glColor3f(1.0f,0.0f,0.0f); 
    glVertex3f(0.0f,0.0f,0.0f); 
    glVertex3f(0.0f,0.2f,0.0f); 
    glVertex3f(0.2f,0.3f,0.0f); 
    glVertex3f(0.4f,0.2f,0.0f); 
    glVertex3f(0.4f,0.0f,0.0f); 
  glEnd(); 
  glBegin( GL_QUADS ); 
    glColor3f(0.0f,0.0f,1.0f); 
    glVertex3f(0.0f,0.0f,0.0f); 
    glVertex3f(0.0f,0.0f,0.4f); 
    glVertex3f(0.0f,0.2f,0.4f); 
    glVertex3f(0.0f,0.2f,0.0f); 
  glEnd(); 
  glBegin( GL_QUAD_STRIP ); 
    glColor3f(0.0f,1.0f,0.0f); 
    glVertex3f(0.0f,0.2f,0.0f); 
    glVertex3f(0.0f,0.2f,0.4f); 
    glVertex3f(0.2f,0.3f,0.0f); 
    glVertex3f(0.2f,0.3f,0.4f); 
    glVertex3f(0.4f,0.2f,0.0f); 
    glVertex3f(0.4f,0.2f,0.4f); 
  glEnd(); 
  glColor3f(1.0f,1.0f,1.0f); 
  glBegin( GL_LINE_STRIP ); 
    glVertex3f(0.0f,0.0f,0.4f); 
    glVertex3f(0.4f,0.0f,0.4f); 
    glVertex3f(0.4f,0.0f,0.0f); 
  glEnd(); 
  glBegin( GL_LINES ); 
    glVertex3f(0.4f,0.0f,0.4f); 
    glVertex3f(0.4f,0.2f,0.4f); 
  glEnd(); 
  glFlush(); 
  glutSwapBuffers(); 
} 
  
void ChangeSize(GLsizei width,GLsizei height) { 
  glViewport(0,0,width,height); 
  glMatrixMode( GL_PROJECTION ); 
  glLoadIdentity(); 
  gluPerspective(30.0,width/height,1.0,10.0); 
} 

void MouseOptions(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON){
      if (state == GLUT_UP) {
        horzangle += 15; 
        RenderScene(); 
      }  
    }

    if (button == GLUT_RIGHT_BUTTON){
      if (state == GLUT_UP) {
        horzangle -= 15; 
        RenderScene();
      }  
    }
         
    glutPostRedisplay();
}
 
void main(int argc, char* argv[]) {
  glutInit(&argc, argv);    
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA ); 
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow("OpenGL - Mouse"); 
  glutReshapeFunc(ChangeSize); 
  glutMouseFunc(MouseOptions);
  glutDisplayFunc(RenderScene);
  glutMainLoop();  
} 
