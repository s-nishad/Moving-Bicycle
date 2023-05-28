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


    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            for(k=0; k<3; k++)
            {
                A[i][j]=A[i][j]+(mat[i][k]*B[k][j]);
            }
        }
    }
}

void rotation_anti_clock(int n,float mat[][3],float ra)
{
    float A[5][3],B[5][3];
    float xp,yp;
    int i,j;
    xp=mat[0][0];
    yp=mat[0][1];

    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            B[i][j]=0;
        }
    }
// This is for anti-clock wise rotation
    B[0][0]=B[1][1]=cos(ra*3.14/180);
    B[0][1]=sin(ra*3.14/180);
    B[1][0]=-sin(ra*3.14/180);
    B[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
    B[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
    B[2][2]=1;

    mul(n,mat,A,B);

    setcolor(WHITE); //white color is our rotation polygon....
    display(n,A);
}
void rotation_clock_wise(int n,float mat[][3],float ra)
{
    float A[5][3],B[5][3];
    float xp,yp;
    int i,j;
    xp=mat[0][0];
    yp=mat[0][1];

    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            B[i][j]=0;
        }
    }
// This is for anti-clock wise rotation
    B[0][0]=B[1][1]=cos(ra*3.14/180);
    B[0][1]=-sin(ra*3.14/180);
    B[1][0]=sin(ra*3.14/180);
    B[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
    B[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
    B[2][2]=1;

    mul(n,mat,A,B);

    setcolor(WHITE); //white color is our rotation polygon....
    display(n,A);
}



int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    float mat[5][3];
    int n;
    float ra;
    printf("Enter number of vertices : \n");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        printf("Enter Coordinates: %d\n",i+1);
        scanf("%f %f",&mat[i][0], &mat[i][1]);
        mat[i][2]=1;
    }
    printf("Enter rotation angle : \n");
    scanf("%f",&ra);

    setcolor(WHITE);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());

    setcolor(GREEN);// green color is our original polygon,,,
    display(n,mat);
    int ch;
    printf("\n ---MENU---");
    printf("\n 1)Rotation in clock wise--");
    printf("\n 2)Rotation in anti-clock wise--");
    printf("\n Enter your Choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        //Reflect about x axisc
        rotation_clock_wise(n, mat,ra);
        break;
    case 2:
        //Reflect about y axis
        rotation_anti_clock(n,mat,ra);
        break;
        default:
        printf("\nInvalid Choice !!!");
        break;

    //rotation(n,mat,ra);


}
   getch();
   closegraph();


}
