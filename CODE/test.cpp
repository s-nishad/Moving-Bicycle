#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;


void display(int n,float mat[][3])
{
    float maxx,maxy;
    maxx=getmaxx()/2;
    maxy=getmaxy()/2;
    int i=0;
    for(i=0; i<n-1; i++)
    {
        line(maxx+mat[i][0],maxy-mat[i][1],maxx+mat[i+1][0],maxy-mat[i+1][1]);
    }
    line(maxx+mat[i][0],maxy-mat[i][1],maxx+mat[0][0],maxy-mat[0][1]);

}

void BoundaryFill(int curPixelX, int curPixelY, int boundaryColor, int fillColor)
{
    //pii pixel = convertPixel(curPixelX,curPixelY);
   // int currColor = getpixel(pixel.first, pixel.second);

    int xc=getmaxx()/2;
    int yc=getmaxy()/2;
    int currColor = getpixel(xc+curPixelX,yc-curPixelY+1);


    if(currColor == boundaryColor || currColor == fillColor) return ;


   // drawPixel(curPixelX, curPixelY, fillColor);
//    int xc=getmaxx()/2;
  //  int yc=getmaxy()/2;
    putpixel(xc+curPixelX,yc-curPixelY+1, fillColor);
    //delay(1);

    BoundaryFill(curPixelX, curPixelY+1, boundaryColor, fillColor);
    BoundaryFill(curPixelX, curPixelY-1, boundaryColor, fillColor);
    BoundaryFill(curPixelX+1, curPixelY, boundaryColor, fillColor);
    BoundaryFill(curPixelX-1, curPixelY, boundaryColor, fillColor);
}


void FloodFill(int curPixelX, int curPixelY, int fillColor, int oldColor)
{
     int xc=getmaxx()/2;
    int yc=getmaxy()/2;
    int currColor = getpixel(xc+curPixelX,yc-curPixelY+1);

    if(currColor != oldColor) return ;
    //drawPixel(curPixelX, curPixelY, fillColor);

    xc=getmaxx()/2;
    yc=getmaxy()/2;
    putpixel(xc+curPixelX,yc-curPixelY+1, fillColor);

    FloodFill(curPixelX, curPixelY+1, fillColor, oldColor);
    FloodFill(curPixelX, curPixelY-1, fillColor, oldColor);
    FloodFill(curPixelX+1, curPixelY, fillColor, oldColor);
    FloodFill(curPixelX-1, curPixelY, fillColor, oldColor);
}


int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    float tx,ty,r;
    float mat[50][3];
    int n;

    setcolor(WHITE);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());

    cout<<"Enter Number of edges for Boundary Fill Algorithm : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number of co-ordinate for Boundary Fill Algorithm : ";
        cin>>mat[i][0]>>mat[i][1];
        mat[i][2]=1;
    }

    setcolor(14);
    display(n,mat);

    BoundaryFill(100,100, YELLOW, RED);


    cout<<"Enter Number of edges for Flodd Fill Algorithm : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number of co-ordinate for Flood Fill Algorithm : ";
        cin>>mat[i][0]>>mat[i][1];
        mat[i][2]=1;
    }

    setcolor(14);
    display(n,mat);

    int xc=getmaxx()/2;
    int yc=getmaxy()/2;
    int currColor = getpixel(xc+(-100),yc-(-100)+1);

    FloodFill(-100,-100, GREEN,currColor);


    //translation(n,mat,tx,ty);
    display(n,mat);
    getch();
    closegraph();
}

