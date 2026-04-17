#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    outtextxy(100, 200, "Wait for 3 seconds...");
    delay(3000);

    cleardevice();
    outtextxy(100, 200, "Done!");

    getch();
    closegraph();
    return 0;
}