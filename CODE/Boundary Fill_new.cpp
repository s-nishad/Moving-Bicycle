#include<stdio.h>
#include<graphics.h>

void boundaryFill8(int x, int y, int fill_color,int boundary_color)
{
	if(getpixel(x, y) != boundary_color &&
	getpixel(x, y) != fill_color)
	{
		putpixel(x, y, fill_color);

		boundaryFill8(x, y-1, fill_color, boundary_color);
		boundaryFill8(x, y+1, fill_color, boundary_color);
		boundaryFill8(x-1, y, fill_color, boundary_color);
		boundaryFill8(x+1, y, fill_color, boundary_color);
		boundaryFill8(x + 1, y + 1, fill_color, boundary_color);
		boundaryFill8(x + 1, y - 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y + 1, fill_color, boundary_color);
		boundaryFill8(x - 1, y - 1, fill_color, boundary_color);
	}
}

int main()
{
	int gd = DETECT, gm;
    int a,b,c,d,x,y;
    printf("Enter Left,Top, Right and Bottom of Rectangle\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("Enter the co-ordinate of the seed\n");
    scanf("%d %d", &x, &y);
	initgraph(&gd, &gm, "");

	rectangle(a, b, c,d);

	boundaryFill8(x, y, 12, 15);

	delay(5000);

	getch();

	closegraph();
    getch();
	return 0;
}
