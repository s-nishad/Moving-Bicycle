#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int main() {
    int x,y,x1,y1,x2,y2,dx,dy,p,i,xmax,ymax;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    xmax=getmaxx();
    ymax=getmaxy();
    line(0,ymax/2,xmax,ymax/2);
    line(xmax/2,0,xmax/2,ymax);
    printf("Enter the values of x0 and y0 :");
    scanf("%d %d",&x1,&y1);
    printf("Enter the values of x1 and y1 :");
    scanf("%d %d",&x2,&y2);


    dx=abs(x2-x1);
    dy=abs(y2-y1);
    p=2*dy-dx;
    x=x1;
    y=y1;
    i=0;
    while(i<= abs(dx)) {
        putpixel(x+xmax/2,ymax/2-y,GREEN);

        delay(200);
        if(p<0) {
            x=x+1;
            p=p+2*dy;
        } else {
            x=x+1;
            y=y+1;
            p=p+2*dy-2*dx;
        }
        i++;
    }
    getch();
    closegraph();
    return 0;

}

