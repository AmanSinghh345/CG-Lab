#include<graphics.h>
#include<conio.h>

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(100,50,"DEFAULT FONT");

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    outtextxy(100,100,"TRIPLEX FONT");

    settextstyle(SMALL_FONT,HORIZ_DIR,4);
    outtextxy(100,160,"SMALL FONT");

    settextstyle(GOTHIC_FONT,HORIZ_DIR,3);
    outtextxy(100,220,"GOTHIC FONT");

    getch();
    closegraph();
}
