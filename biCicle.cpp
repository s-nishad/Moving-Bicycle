#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

int main() {
    system("cls");
    int gd = DETECT, gm,i,a;
    initgraph(&gd, &gm, " ");

    for(i=0; i<600; i++) {

        //cycle

        line(50+i,405,100+i,405);
        line(75+i,375,125+i,375);
        line(50+i,405,75+i,375);
        line(100+i,405,125+i,375);
        line(150+i,405,100+i,345);
        line(75+i,375,75+i,370);
        line(70+i,370,80+i,370);
        line(80+i,345,100+i,345);

        //wheel//

        circle(150+i,405,30);
        circle(50+i,405,30);

        //road//

        line(0,436,getmaxx(),436);

        //stone//

        rectangle(getmaxx()-i,436,650-i,431);

        delay(10);
        cleardevice();
    }

    getch();
    closegraph();

}

