#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1 = 200, y1 = 200, x2 = 250, y2 = 150, x3 = 300, y3 = 200;
    int choice;

    do
    {
        cleardevice();
        drawTriangle(x1, y1, x2, y2, x3, y3);

        cout << "\n1 Translation";
        cout << "\n2 Scaling";
        cout << "\n3 Rotation";
        cout << "\n4 Shearing";
        cout << "\n5 Reflection (X-axis)";
        cout << "\n6 Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int tx, ty;
            cout << "Enter tx ty: ";
            cin >> tx >> ty;

            x1 += tx;
            y1 += ty;
            x2 += tx;
            y2 += ty;
            x3 += tx;
            y3 += ty;
            break;
        }

        case 2:
        {
            float sx, sy;
            cout << "Enter sx sy: ";
            cin >> sx >> sy;

            x1 = x1 * sx;
            y1 = y1 * sy;
            x2 = x2 * sx;
            y2 = y2 * sy;
            x3 = x3 * sx;
            y3 = y3 * sy;
            break;
        }

        case 3:
        {
            float angle, rad;
            cout << "Enter rotation angle: ";
            cin >> angle;

            rad = angle * 3.14 / 180;

            int nx1 = x1 * cos(rad) - y1 * sin(rad);
            int ny1 = x1 * sin(rad) + y1 * cos(rad);

            int nx2 = x2 * cos(rad) - y2 * sin(rad);
            int ny2 = x2 * sin(rad) + y2 * cos(rad);

            int nx3 = x3 * cos(rad) - y3 * sin(rad);
            int ny3 = x3 * sin(rad) + y3 * cos(rad);

            x1 = nx1;
            y1 = ny1;
            x2 = nx2;
            y2 = ny2;
            x3 = nx3;
            y3 = ny3;
            break;
        }

        case 4:
        {
            float shx, shy;
            cout << "Enter shx shy: ";
            cin >> shx >> shy;

            int nx1 = x1 + shx * y1;
            int ny1 = y1 + shy * x1;

            int nx2 = x2 + shx * y2;
            int ny2 = y2 + shy * x2;

            int nx3 = x3 + shx * y3;
            int ny3 = y3 + shy * x3;

            x1 = nx1;
            y1 = ny1;
            x2 = nx2;
            y2 = ny2;
            x3 = nx3;
            y3 = ny3;
            break;
        }

        case 5:
        {
            y1 = 480 - y1;
            y2 = 480 - y2;
            y3 = 480 - y3;
            break;
        }
        }

    } while (choice != 6);

    closegraph();
}