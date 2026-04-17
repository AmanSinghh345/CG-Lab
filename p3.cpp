#include <GL/freeglut.h>

void drawCircle(int xc,int yc,int r){
    int x=0,y=r;
    int d=3-2*r;

    glBegin(GL_POINTS);
    while(x<=y){
        glVertex2i(xc+x,yc+y);
        glVertex2i(xc-x,yc+y);
        glVertex2i(xc+x,yc-y);
        glVertex2i(xc-x,yc-y);
        glVertex2i(xc+y,yc+x);
        glVertex2i(xc-y,yc+x);
        glVertex2i(xc+y,yc-x);
        glVertex2i(xc-y,yc-x);

        if(d<0) d+=4*x+6;
        else{
            d+=4*(x-y)+10;
            y--;
        }
        x++;
    }
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle(250,250,100);
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
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
