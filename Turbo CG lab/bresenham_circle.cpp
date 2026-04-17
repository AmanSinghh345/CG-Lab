#include<graphics.h>
#include<conio.h>

void drawcircle(int xc,int yc,int x,int y)
{
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc-x,yc-y,WHITE);
    putpixel(xc+y,yc+x,WHITE);
    putpixel(xc-y,yc+x,WHITE);
    putpixel(xc+y,yc-x,WHITE);
    putpixel(xc-y,yc-x,WHITE);
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    int xc=250, yc=250, r=100;
    int x=0, y=r;
    int d=3-2*r;

    while(x<=y)
    {
        drawcircle(xc,yc,x,y);

        if(d<0)
            d=d+4*x+6;
        else
        {
            d=d+4*(x-y)+10;
            y--;
        }
        x++;
    }

    getch();
    closegraph();
}
