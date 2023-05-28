#include<stdio.h>
#include <graphics.h>

// Function for 8 connected Pixels
void boundaryFill8(int x, int y, int fill_color,int boundary_color)
{
    if(getpixel(x, y) != boundary_color &&
     getpixel(x, y) != fill_color)
    {
        putpixel(x, y, fill_color);

        boundaryFill8(x, y+1, fill_color, boundary_color);// replace the boundary color with fill color
        boundaryFill8(x, y-1, fill_color, boundary_color);
        boundaryFill8(x+1, y, fill_color, boundary_color);
        boundaryFill8(x-1, y, fill_color, boundary_color);

        boundaryFill8(x + 1, y + 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y - 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y + 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y - 1, fill_color, boundary_color);
    }
}


int main()
{

    int gd = DETECT, gm;
    int a,b,c,d,x,y,p,q,xmax,ymax;
    printf("Enter the left and top of Rectangle\n");
    scanf("%d %d", &a, &b);
    printf("Enter the right and bottom of Rectangle\n");
    scanf("%d %d", &c, &d);
    printf(" Enter the co-ordinate of the seed\n");
    printf("\nplease Enter the value between X1 and X2 \n Y1 and Y2\n");
    scanf("%d %d", &x, &y);

    initgraph(&gd, &gm, "");
    xmax=getmaxx();
    ymax=getmaxy();
    line(xmax/2,0,xmax/2,ymax);
    line(0,ymax/2,xmax,ymax/2);
   //Rectangle function
    rectangle(xmax/2+a, ymax/2-b, xmax/2+c, ymax/2-d);
    boundaryFill8(xmax/2+x, ymax/2-y, GREEN,WHITE);

    delay(30);

    getch();


    closegraph();

    return 0;
}

