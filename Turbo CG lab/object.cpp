#include<graphics.h>
#include<conio.h>

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    rectangle(50,50,200,150);
    circle(300,100,50);
    line(400,50,500,150);
    ellipse(300,250,0,360,80,40);

    getch();
    closegraph();
}
