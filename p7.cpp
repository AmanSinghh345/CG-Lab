#include <GL/freeglut.h>
#include <cmath>

int x=0;

void drawCircle(int xc,int yc,int r){
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        float th=i*3.1416/180;
        glVertex2f(xc+r*cos(th),yc+r*sin(th));
    }
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle(x,250,50);
    glFlush();
}

void update(int v){
    x+=2;
    if(x>500) x=0;
    glutPostRedisplay();
    glutTimerFunc(30,update,0);
}

void init(){
    glClearColor(1,1,1,1);
    glColor3f(0,0,0);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Moving Circle");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0,update,0);
    glutMainLoop();
}
