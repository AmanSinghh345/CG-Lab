#include<graphics.h>
#include<conio.h>

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    int x1=100, y1=100, x2=300, y2=200;
    int dx = x2-x1;
    int dy = y2-y1;
    int p = 2*dy - dx;
    int x=x1, y=y1;

    while(x<=x2)
    {
        putpixel(x,y,WHITE);
        x++;

        if(p<0)
            p += 2*dy;
        else
        {
            y++;
            p += 2*(dy-dx);
        }
    }

    getch();
    closegraph();
}
