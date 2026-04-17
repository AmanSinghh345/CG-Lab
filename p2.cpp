#include <GL/freeglut.h>
#include <cmath>

void drawLine(int x1,int y1,int x2,int y2){
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int p=2*dy-dx;

    int x=x1,y=y1;

    glBegin(GL_POINTS);
    while(x<=x2){
        glVertex2i(x,y);
        x++;
        if(p<0) p+=2*dy;
        else{
            y++;
            p+=2*(dy-dx);
        }
    }
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawLine(100,100,400,300);
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
    glutCreateWindow("Bresenham Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
