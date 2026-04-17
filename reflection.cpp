#include <graphics.h>
#include <conio.h>

void main()
{
    int gd = DETECT, gm;
    int x = 150, y = 150;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Original
    putpixel(x, y, WHITE);

    // Reflection about X-axis
    putpixel(x, -y + 300, WHITE);

    getch();
    closegraph();
}