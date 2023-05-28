#include<stdio.h>
#include<graphics.h>
#include <conio.h>


int main() {
    int gd=DETECT,gm,xmax,ymax;
    float x,y,xc,yc,rx,ry,p_old,p_new;
    initgraph(&gd,&gm,"");
    xmax=getmaxx();
    ymax=getmaxy();
    line(0,ymax/2,xmax,ymax/2);
    line(xmax/2,0,xmax/2,ymax);


    printf("Mid point ellipse drawing algorithm\n");
    printf("Enter Center for ellipse\nx : ");
    scanf("%f",&xc);
    printf("y : ");
    scanf("%f",&yc);
    printf("Enter x-radius and y-radius\nx-radius : ");
    scanf("%f",&rx);
    printf("y-radius : ");
    scanf("%f",&ry);
    xc=xc+xmax/2;
    yc=ymax/2-yc;
    x=0;
    y=ry;
// for region 1
    p_old=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
    while((2*x*ry*ry)<(2*y*rx*rx)) {
        if(p_old<0) {
            x=x+1;
            p_new=p_old+(2*ry*ry*x)+(ry*ry);
        } else {
            x=x+1;
            y=y-1;
            p_new=p_old+(2*ry*ry*x)-(2*rx*rx*y)+(ry*ry);
        }
        p_old=p_new;
        putpixel(xc+x,yc+y,GREEN);
        putpixel(xc-x,yc+y,GREEN);
        putpixel(xc+x,yc-y,GREEN);
        putpixel(xc-x,yc-y,GREEN);

    }
// for region_2
    p_old=((x+0.5)*(x+0.5)*ry*ry)+((y-1)*(y-1)*rx*rx)-(rx*rx*ry*ry);
    while(y>=0) {
        if(p_old>0) {
            y=y-1;
            p_new=p_old-(2*rx*rx*y)+(rx*rx);
        } else {
            x=x+1;
            y=y-1;
            p_new=p_old+(2*ry*ry*x)-(2*rx*rx*y)+(rx*rx);
        }
        p_old=p_new;
        putpixel(xc+x,yc+y,YELLOW);
        putpixel(xc-x,yc+y,YELLOW);
        putpixel(xc+x,yc-y,YELLOW);
        putpixel(xc-x,yc-y,YELLOW);

    }

    getch(); //Pauses the Output Console until a key is pressed
    closegraph();
    return 0;
}
