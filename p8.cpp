#include <GL/freeglut.h>
#include <windows.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

    Sleep(2000);   // Delay BEFORE drawing

    glBegin(GL_LINES);
    glVertex2i(100,100);
    glVertex2i(400,400);
    glEnd();

    glFlush();
}

void init(){
    glClearColor(1,1,1,1);
    glColor3f(0,0,0);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Delay Function");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
