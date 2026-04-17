#include <GL/freeglut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // Rectangle
    glBegin(GL_QUADS);
    glVertex2i(100,100);
    glVertex2i(200,100);
    glVertex2i(200,200);
    glVertex2i(100,200);
    glEnd();

    // Triangle
    glBegin(GL_TRIANGLES);
    glVertex2i(300,100);
    glVertex2i(400,100);
    glVertex2i(350,200);
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
    glutCreateWindow("2D Objects");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
