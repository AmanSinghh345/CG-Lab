#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void bezier(int x[], int y[])
{
    float t;
    int xt, yt;

    for (t = 0; t <= 1; t += 0.001)
    {
        xt = pow(1 - t, 3) * x[0] +
             3 * t * pow(1 - t, 2) * x[1] +
             3 * t * t * (1 - t) * x[2] +
             t * t * t * x[3];

        yt = pow(1 - t, 3) * y[0] +
             3 * t * pow(1 - t, 2) * y[1] +
             3 * t * t * (1 - t) * y[2] +
             t * t * t * y[3];

        putpixel(xt, yt, WHITE);
    }
}

void main()
{
    int gd = DETECT, gm;
    int x[4], y[4];
    int i;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    cout << "Enter 4 control points\n";

    for (i = 0; i < 4; i++)
    {
        cout << "x" << i << " y" << i << ": ";
        cin >> x[i] >> y[i];
    }

    setcolor(RED);

    for (i = 0; i < 3; i++)
    {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }

    bezier(x, y);

    getch();
    closegraph();
}