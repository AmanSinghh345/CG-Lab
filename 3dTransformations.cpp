#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

float x[8]={100,200,200,100,120,220,220,120};
float y[8]={100,100,200,200,120,120,220,220};
float z[8]={0,0,0,0,100,100,100,100};

void drawCube()
{
    int i;

    // front face
    for(i=0;i<4;i++)
        line(x[i],y[i],x[(i+1)%4],y[(i+1)%4]);

    // back face
    for(i=4;i<8;i++)
        line(x[i],y[i],x[4+(i+1)%4],y[4+(i+1)%4]);

    // connecting edges
    for(i=0;i<4;i++)
        line(x[i],y[i],x[i+4],y[i+4]);
}

void main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    int choice,i;

    do
    {
        cleardevice();
        drawCube();

        cout<<"\n1 Translation";
        cout<<"\n2 Scaling";
        cout<<"\n3 Rotation (Z axis)";
        cout<<"\n4 Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                float tx,ty,tz;
                cout<<"Enter tx ty tz: ";
                cin>>tx>>ty>>tz;

                for(i=0;i<8;i++)
                {
                    x[i]+=tx;
                    y[i]+=ty;
                    z[i]+=tz;
                }
                break;
            }

            case 2:
            {
                float sx,sy,sz;
                cout<<"Enter sx sy sz: ";
                cin>>sx>>sy>>sz;

                for(i=0;i<8;i++)
                {
                    x[i]*=sx;
                    y[i]*=sy;
                    z[i]*=sz;
                }
                break;
            }

            case 3:
            {
                float angle,rad;
                cout<<"Enter rotation angle: ";
                cin>>angle;

                rad=angle*3.14/180;

                for(i=0;i<8;i++)
                {
                    float nx = x[i]*cos(rad) - y[i]*sin(rad);
                    float ny = x[i]*sin(rad) + y[i]*cos(rad);

                    x[i]=nx;
                    y[i]=ny;
                }
                break;
            }

        }

    }while(choice!=4);

    closegraph();
}