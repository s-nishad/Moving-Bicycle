#include<graphics.h>
#include<stdio.h>

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
int main() {
    int gd,gm,r;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,(char*)"");


    MidPointCircle(150, 405, 30);
    MidPointCircle(130, 405, 30);
    MidPointCircle(160, 405, 30);

    getch();
    closegraph();
    return 0;
}


