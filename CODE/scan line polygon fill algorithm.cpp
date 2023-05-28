#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int  main()
{
    int n,i,j,k,gd,gm,dy,dx,xmax,ymax;
    gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    int x,y,temp;
    int a[20][2],xi[20];
    float slope[20];

    printf("\n\n\tEnter the no. of edges of polygon : ");
    scanf("%d",&n);
    printf("\n\n\tEnter the cordinates of polygon :\n\n\n ");
    for(i=0,j=0; i<n&&j<n; i++,j++)
    {
        printf("\tX%d Y%d : ",i,j);
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    a[n][0]=a[0][0];
    a[n][1]=a[0][1];

    xmax=getmaxx();
    ymax=getmaxy();
    line(xmax/2,0,xmax/2,ymax); // y axix er jonno
    line(0,ymax/2,xmax,ymax/2);// x axis er jonno

    /*- draw polygon -*/
    for(i=0; i<n; i++)
    {
        //line(xmax/2+a[i][0],ymax/2-a[i][1],xmax/2+a[i+1][0],ymax/2-a[i+1][1]);
        line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    }
    //line(a[i][0],a[i][1],a[0][0],a[0][1]);
    getch();
    //slope calculation
    for(i=0; i<n; i++)
    {
        dy=a[i+1][1]-a[i][1];
        dx=a[i+1][0]-a[i][0];
        if(dy==0) slope[i]=1.0;
        if(dx==0) slope[i]=0.0;
        if((dy!=0)&&(dx!=0)) /*- calculate inverse slope -*/
        {
            slope[i]=(float) dx/dy;
        }
    }
    for(y=0; y< 480; y++)
    {
        k=0;
        for(i=0; i<n; i++)

        {
            if( ((a[i][1]<=y)&&(a[i+1][1]>y))|| // clock wise direction y value decreasing and y value increasing
                    ((a[i][1]>y)&&(a[i+1][1]<=y)))// y value increasing y value decreasing.
            {
                xi[k]=(int)(a[i][0]+slope[i]*(y-a[i][1]));
                k++;
            }
        }
        for(j=0; j<k-1; j++)
            for(i=0; i<k-1; i++)
            {
                if(xi[i]>xi[i+1])
                {
                    temp=xi[i];
                    xi[i]=xi[i+1];
                    xi[i+1]=temp;
                }

              }
        setcolor(GREEN);
        for(i=0; i<k; i+=2)
        {
            line(xi[i],y,xi[i+1]+1,y);
            getch();
        }
    }
    return 0;
}

