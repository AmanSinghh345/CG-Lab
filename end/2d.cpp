#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    // NOTE: Change this path if your BGI folder is located elsewhere
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Original Triangle Coordinates
    int x1 = 150, y1 = 150;
    int x2 = 250, y2 = 150;
    int x3 = 200, y3 = 50;

    int choice;
    float tx, ty, sx, sy, angle, rad, shx, shy;
    int nx1, ny1, nx2, ny2, nx3, ny3;

    while(1) {
        cleardevice();
        cout << "--- 2D Transformations ---\n";
        cout << "1. Translation\n";
        cout << "2. Scaling\n";
        cout << "3. Rotation\n";
        cout << "4. Shearing\n";
        cout << "5. Reflection\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) break;

        cleardevice();
        setcolor(WHITE);
        outtextxy(10, 10, "Original Object (White)");
        drawTriangle(x1, y1, x2, y2, x3, y3);

        setcolor(YELLOW);
        outtextxy(10, 25, "Transformed Object (Yellow)");

        switch(choice) {
            case 1: // Translation
                cout << "\nEnter Translation factors (tx ty): ";
                cin >> tx >> ty;
                nx1 = x1 + tx; ny1 = y1 + ty;
                nx2 = x2 + tx; ny2 = y2 + ty;
                nx3 = x3 + tx; ny3 = y3 + ty;
                drawTriangle(nx1, ny1, nx2, ny2, nx3, ny3);
                break;

            case 2: // Scaling (Relative to origin, can be modified for relative to fixed point)
                cout << "\nEnter Scaling factors (sx sy): ";
                cin >> sx >> sy;
                nx1 = x1 * sx; ny1 = y1 * sy;
                nx2 = x2 * sx; ny2 = y2 * sy;
                nx3 = x3 * sx; ny3 = y3 * sy;
                drawTriangle(nx1, ny1, nx2, ny2, nx3, ny3);
                break;

            case 3: // Rotation (Relative to origin 0,0)
                cout << "\nEnter Rotation angle (in degrees): ";
                cin >> angle;
                // Convert degrees to radians
                rad = angle * (3.14159 / 180.0);
                nx1 = abs(x1 * cos(rad) - y1 * sin(rad));
                ny1 = abs(x1 * sin(rad) + y1 * cos(rad));
                nx2 = abs(x2 * cos(rad) - y2 * sin(rad));
                ny2 = abs(x2 * sin(rad) + y2 * cos(rad));
                nx3 = abs(x3 * cos(rad) - y3 * sin(rad));
                ny3 = abs(x3 * sin(rad) + y3 * cos(rad));
                drawTriangle(nx1, ny1, nx2, ny2, nx3, ny3);
                break;

            case 4: // Shearing
                int shearChoice;
                cout << "\n1. X-Shear\n2. Y-Shear\nEnter choice: ";
                cin >> shearChoice;
                if(shearChoice == 1) {
                    cout << "Enter X-Shear value: ";
                    cin >> shx;
                    nx1 = x1 + shx * y1; ny1 = y1;
                    nx2 = x2 + shx * y2; ny2 = y2;
                    nx3 = x3 + shx * y3; ny3 = y3;
                } else {
                    cout << "Enter Y-Shear value: ";
                    cin >> shy;
                    nx1 = x1; ny1 = y1 + shy * x1;
                    nx2 = x2; ny2 = y2 + shy * x2;
                    nx3 = x3; ny3 = y3 + shy * x3;
                }
                drawTriangle(nx1, ny1, nx2, ny2, nx3, ny3);
                break;

            case 5: // Reflection
                int refChoice;
                // Get the maximum coordinates of the screen for accurate reflection
                int maxx = getmaxx();
                int maxy = getmaxy();
                
                cout << "\n1. Reflection across X-axis (horizontal flip)\n";
                cout << "2. Reflection across Y-axis (vertical flip)\n";
                cout << "Enter choice: ";
                cin >> refChoice;

                if(refChoice == 1) {
                    // Reflecting across a horizontal line at the middle of the screen
                    nx1 = x1; ny1 = maxy - y1;
                    nx2 = x2; ny2 = maxy - y2;
                    nx3 = x3; ny3 = maxy - y3;
                } else {
                    // Reflecting across a vertical line at the middle of the screen
                    nx1 = maxx - x1; ny1 = y1;
                    nx2 = maxx - x2; ny2 = y2;
                    nx3 = maxx - x3; ny3 = y3;
                }
                drawTriangle(nx1, ny1, nx2, ny2, nx3, ny3);
                break;

            default:
                cout << "Invalid choice!\n";
        }
        cout << "\nPress any key to continue...";
        getch();
    }

    closegraph();
    return 0;
}