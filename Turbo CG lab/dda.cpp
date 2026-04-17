#include<graphics.h>
#include<conio.h>
#include<math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    float x1=100, y1=100, x2=300, y2=200;
    float dx = x2-x1;
    float dy = y2-y1;
    float steps, xinc, yinc, x, y;

    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xinc = dx/steps;
    yinc = dy/steps;

    x = x1;
    y = y1;

    for(int i=0;i<=steps;i++)
    {
        putpixel(x,y,WHITE);
        x += xinc;
        y += yinc;
    }

    getch();
    closegraph();
}
