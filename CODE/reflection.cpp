
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

void Reflection_on_x_axis(int n,float mat[][3])
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
    B[0][0]=B[2][2]=1;
    B[1][1]=-1;
    mul(n,mat,A,B);


    setcolor(RED); // Red color for after reflection
    display(n,A);
}


void Reflection_on_y_axis(int n,float mat[][3])
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
    B[0][0]=-1;
    B[1][1]=B[2][2]=1;
    mul(n,mat,A,B);


    setcolor(RED);
    display(n,A);
}


void Reflection_on_origin_axis(int n,float mat[][3])
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
    B[0][0]=B[1][1]=-1;
    B[2][2]=1;
    mul(n,mat,A,B);


    setcolor(YELLOW);
    display(n,A);
}
void Reflection_on_y_equal_x_axis(int n,float mat[][3])
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
    B[0][1]=B[1][0]=1;
    B[2][2]=1;
    mul(n,mat,A,B);


    setcolor(YELLOW);
    display(n,A);
}

void Reflection_on_y_equal_neg_x_axis(int n,float mat[][3])
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
    B[0][1]=B[1][0]=-1;
    B[2][2]=1;
    mul(n,mat,A,B);

    setcolor(RED);
    display(n,A);
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    float mat[5][3];
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

    setcolor(WHITE);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());

    setcolor(GREEN);// green color before rotation.
    display(n,mat);

    int ch;
    printf("\n ---MENU---");
    printf("\n 1)Reflection about x axis");
    printf("\n 2)Reflection about y axis");
    printf("\n 3)Reflection on origin axis");
    printf("\n 4)Reflection about the line y=x");
    printf("\n 5)Reflection about the line y=-x");
    printf("\n Enter your Choice: ");

    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        //Reflect about x axisc
        Reflection_on_x_axis(n,mat);
        break;
    case 2:
        //Reflect about y axis
        Reflection_on_y_axis(n,mat);
        break;
    case 3:
        //Reflect about origin
         Reflection_on_origin_axis(n,mat);
        break;
    case 4:
        //Reflect about line y=x
        Reflection_on_y_equal_x_axis(n,mat);
        break;
    case 5:
        //Reflect about line y=-x
        Reflection_on_y_equal_neg_x_axis(n,mat);
        break;
        default:
        printf("\nInvalid Choice !!!");
        break;

    }

    getch();
    closegraph();

}
