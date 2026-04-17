#include <GL/freeglut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(6);
    glBegin(GL_POINTS);
    glVertex2i(250,250);
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
    glutCreateWindow("Point Pixel");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
