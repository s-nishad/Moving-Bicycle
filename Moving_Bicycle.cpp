#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;


void Bresenham_LineDraw (int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        putpixel(x0, y0, WHITE);

        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void MidPointCircle (int xc, int yc, int r) {
    int x,y,p;
    x=0;
    y=r;
    p=1-r;
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc-x,yc-y,WHITE);
    putpixel(xc+y,yc+x,WHITE);
    putpixel(xc+y,yc-x,WHITE);
    putpixel(xc-y,yc+x,WHITE);
    putpixel(xc-y,yc-x,WHITE);

    while(x<=y) {
        if(p<0) {
            x++;
            p=p+2*x+1;
        } else {
            x++;
            y--;
            p=p+2*(x-y)+1;
        }
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        putpixel(xc+y,yc+x,WHITE);
        putpixel(xc+y,yc-x,WHITE);
        putpixel(xc-y,yc+x,WHITE);
        putpixel(xc-y,yc-x,WHITE);
    }
}

void Rectangle_Draw(int left, int top, int right, int bottom, int color) {
    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            putpixel(x, y, color);
        }
    }
}


int main() {
    system("cls");
    int gd = DETECT, gm,i,a;
    initgraph(&gd, &gm, " ");

    for (int i = 0; i < 600; i++) {
        // cycle
        Bresenham_LineDraw(50+i, 405, 100+i, 405);
        Bresenham_LineDraw(75+i, 375, 125+i, 375);
        Bresenham_LineDraw(50+i, 405, 75+i, 375);
        Bresenham_LineDraw(100+i, 405, 125+i, 375);
        Bresenham_LineDraw(150+i, 405, 100+i, 345);
        Bresenham_LineDraw(75+i, 375, 75+i, 370);
        Bresenham_LineDraw(70+i, 370, 80+i, 370);
        Bresenham_LineDraw(80+i, 345, 100+i, 345);



        // wheel
        MidPointCircle(150+i, 405, 30);
        MidPointCircle(50+i, 405, 30);

        // road
        Bresenham_LineDraw(0, 436, getmaxx(), 436);

        // street breaker
        rectangle(getmaxx()-i, 436, 650-i, 431);

        delay(10);
        cleardevice();
    }

    getch();
    closegraph();

}

