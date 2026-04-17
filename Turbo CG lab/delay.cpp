#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    circle(200, 200, 50);
    delay(2000);

    cleardevice();
    outtextxy(150, 200, "After Delay");

    getch();
    closegraph();
}
