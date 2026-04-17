#include<graphics.h>
#include<conio.h>
#include<dos.h>

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    for(int x=50;x<500;x++)
    {
        cleardevice();
        circle(x,200,40);
        delay(50);
    }

    getch();
    closegraph();
}
