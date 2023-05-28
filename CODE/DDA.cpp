#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void DDA(int x1, int y1, int x2, int y2) {
    float x,y,dx,dy,step;
    int i;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(dx>=dy)
        step=dx;
    else
        step=dy;

    dx=dx/step;
    dy=dy/step;

    x=x1;
    y=y1;

    i=1;
    while(i<=step) {
        putpixel(x,y,5);
        x=x+dx;
        y=y+dy;
        i=i+1;
        delay(100);
    }
}


int main( ) {
    int gd = DETECT,gm;

    initgraph(&gd,&gm," ");

    DDA(20, 30, 40, 70);




    closegraph();
}
