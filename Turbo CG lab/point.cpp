#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    putpixel(200, 200, WHITE);

    getch();
    closegraph();
    return 0;
}
