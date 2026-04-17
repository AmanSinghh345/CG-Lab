#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x = 50, y = 200;

    for (int i = 0; i < 400; i++) {
        cleardevice();
        circle(x + i, y, 30);
        delay(20);
    }

    getch();
    closegraph();
    return 0;
}