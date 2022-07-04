#include <windows.h> 
#include <gl\gl.h> 
#include <gl\glaux.h> 
  
GLfloat angle = -45.0f; 
  
void CALLBACK RenderScene(void) { 
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
  auxSwapBuffers(); 
} 
  
void CALLBACK ChangeSize(GLsizei width,GLsizei height) { 
  glViewport(0,0,width,height); 
  glMatrixMode( GL_PROJECTION ); 
  glLoadIdentity(); 
  gluPerspective(30.0,width/height,1.0,10.0); 
  glMatrixMode( GL_MODELVIEW ); 
  glLoadIdentity(); 
  glTranslatef(0.0f,0.0f,-3.0f); 
  glRotatef(30.0f,1.0f,0.0f,0.0f); 
  glRotatef(angle,0.0f,1.0f,0.0f); 
} 
  
void CALLBACK IdleFunction(void) { 
  angle -= 5; 
  if (angle == -360) angle = 0; 
  glMatrixMode( GL_MODELVIEW ); 
  glLoadIdentity(); 
  glTranslatef(0.0f,0.0f,-3.0f); 
  glRotatef(30.0f,1.0f,0.0f,0.0f); 
  glRotatef(angle,0.0f,1.0f,0.0f); 
  RenderScene(); 
} 
  
void main(void) { 
  auxInitDisplayMode( AUX_DOUBLE | AUX_DEPTH | AUX_RGBA ); 
  auxInitPosition(100,100,320,240); 
  auxInitWindow("OpenGL - Animação"); 
  auxReshapeFunc(ChangeSize); 
  auxIdleFunc(IdleFunction); 
  auxMainLoop(RenderScene); 
} 
