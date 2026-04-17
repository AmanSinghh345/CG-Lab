#include <GL/freeglut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glRasterPos2f(50,250);
    char t1[]="Computer Graphics Lab";
    for(int i=0;t1[i]!='\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,t1[i]);

    glRasterPos2f(50,200);
    char t2[]="Different Font Example";
    for(int i=0;t2[i]!='\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,t2[i]);

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
    glutCreateWindow("Fonts");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
