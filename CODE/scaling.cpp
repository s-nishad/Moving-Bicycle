#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>


void display(int n,float mat[][3])
{
    float maxx,maxy;
    maxx=getmaxx()/2;
    maxy=getmaxy()/2;
    int i;
    for(i=0; i<n-1; i++)
    {
        line(maxx+mat[i][0],maxy-mat[i][1],maxx+mat[i+1][0],maxy-mat[i+1][1]);
    }
    line(maxx+mat[i][0],maxy-mat[i][1],maxx+mat[0][0],maxy-mat[0][1]);

}

void mul(int n,float mat[][3],float A[][3],float B[][3])
{
    int i,j,k;

    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            A[i][j]=0;
        }
    }

    for(i=0; i<n; i++)  // i use for  handling row
    {
        for(j=0; j<3; j++)// handling column
        {
            for(k=0; k<3; k++)// k value should be number of column in 1st matrix or row in second matrix
            {
                A[i][j]=A[i][j]+(mat[i][k]*B[k][j]);
            }
        }
    }
}

void scaling(int n,float mat[][3],float sx,float sy)
{
    float A[50][3],B[50][3];// b matrix for store scaling factor
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            B[i][j]=0;
        }
    }

    B[0][0]=sx;
    B[1][1]=sy;
    B[2][2]=1;
    mul(n,mat,A,B);

    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("  %d  ",int(A[i][j]));
        }
        printf("\n");
    }
    printf("\n");

    setcolor(GREEN);// this is our scaling color polygon image
    display(n,A);
}


int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    float mat[50][3];
    int n;
    float sx,sy;
    printf("Enter number of vertices : \n");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        printf("Enter Coordinates: %d\n",i+1);
        scanf("%f %f",&mat[i][0],&mat[i][1]);
        mat[i][2]=1;
    }
    printf("Enter scaling values : sx \n");

    scanf("%f",&sx);
    printf("Enter scaling values : sy \n");
    scanf("%f",&sy);

    //setcolor(WHITE);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());

    setcolor(YELLOW); //this is color for before scaling
    display(n,mat);

    scaling(n,mat,sx,sy);

   getch();
   closegraph();


}
