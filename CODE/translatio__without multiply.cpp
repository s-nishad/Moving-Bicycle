#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

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

void translation(int n, float mat[][3],float tx, float ty)
{
    for(int i=0; i<n; i++)
    {
        mat[i][0]+=tx;
        mat[i][1]+=ty;
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    float tx,ty,r;
    float mat[5][3];
    int n;
    printf("Enter number of edges: \n");
    scanf("%d",&n);
   // printf("Enter Coordinates: \n");
    for(int i=0; i<n; i++)
    {
        printf("Enter Coordinates: %d\n",i+1);
        scanf("%f %f",&mat[i][0],&mat[i][1]);
        mat[i][2]=1;
    }
    printf("Enter translation distance: tx \n");
    scanf("%f",&tx);
    printf("Enter translation distance: ty\n");
    scanf("%f",&ty);
    setcolor(WHITE);

    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    setcolor(GREEN);// Green is our original polygon
    display(n,mat);
    setcolor(RED);//  RED  is our translation polygon
    translation(n,mat,tx,ty);
    display(n,mat);
    getch();
    closegraph();
}

