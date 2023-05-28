// 4 0,0 0,50 50,50 50,0 2
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


void shearx(int n,float mat[][3],float shx)
{
    float A[5][3],B[5][3];
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            B[i][j]=0;// B matrix er value zero kora hooilo.
        }
    }
    B[1][0]=shx;
    B[0][0]=B[1][1]=B[2][2]=1;
    mul(n,mat,A,B);


    setcolor(RED);
    display(n,A);
}


void sheary(int n,float mat[][3],float shy)
{
    float A[5][3],B[5][3];
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            B[i][j]=0;
        }
    }
    B[0][1]=shy;
    B[0][0]=B[1][1]=B[2][2]=1;
    mul(n,mat,A,B);


    setcolor(RED); // RED color for after shearing
    display(n,A);
}


void shearxy(int n,float mat[][3],float shx, float shy)
{
    float A[5][3],B[5][3];
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            B[i][j]=0;
        }
    }

    B[0][1]=shy;
    B[1][0]=shx;
    B[0][0]=B[1][1]=B[2][2]=1;
    mul(n,mat,A,B);


    setcolor(RED);//RED color for after shearing
    display(n,A);
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    float mat[5][3];
    int n;
    float shx,shy;
    printf("Enter number of vertices : \n");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        printf("Enter Coordinates: %d\n",i+1);
        scanf("%f %f",&mat[i][0],&mat[i][1]);
        mat[i][2]=1;
    }

    setcolor(WHITE);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());

    setcolor(GREEN);// GREEN color for our original polygon
    display(n,mat);

    int ch;
    printf("\n ---MENU---");
    printf("\n 1)X-shear");
    printf("\n 2)Y-shear");
    printf("\n 3)XY-shear");
    printf("\nEnter your Choice: ");


    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        //Enter shearing factor ShX
        printf("\nEnter Shear factor: SHx ");
        scanf("%f",&shx);
        shearx(n,mat,shx);
        break;
    case 2:
        //Enter shearing factor Shy
        printf("\nEnter Shear factor: SHy ");
        scanf("%f",&shy);
        sheary(n,mat,shy);
        break;
    case 3:
        //Enter shearing factors Shx and Shy
        printf("\nEnter Shear factor Shx : ");
        scanf("%f",&shx);
        printf("\nEnter Shear factor Shy: ");
        scanf("%f",&shy);
        shearxy(n,mat,shx,shy);
        break;
    default:
        printf("\nInvalid Choice !!!");
        break;
    }

    getch();
    closegraph();

}

