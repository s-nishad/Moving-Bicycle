#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void Bresenham_LineDraw(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        putpixel(x0, y0, WHITE);

        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void MidPointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (p < 0) {
            p += 2 * x + 3;
        } else {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");

    int maxX = getmaxx();
    int maxY = getmaxy();
    int centerX = maxX / 2;
    int centerY = maxY / 2;
    int radius = 30;
    int wheelOffset = 55;
    int wheelY = centerY + wheelOffset;

    for (int i = 0; i < 600; i++) {
        // Clear the screen with black color
        setbkcolor(BLACK);
        cleardevice();

        // Draw road
        Bresenham_LineDraw(0, centerY + wheelOffset + radius, maxX, centerY + wheelOffset + radius);

        // Draw stone
        Bresenham_LineDraw(maxX - i, centerY + wheelOffset + radius, maxX - i + 5, centerY + wheelOffset + radius);

        // Draw wheels
        MidPointCircle(centerX + i, wheelY, radius);
        MidPointCircle(centerX - wheelOffset + i, wheelY, radius);

        // Draw bicycle body
        Bresenham_LineDraw(centerX + i, centerY + wheelOffset, centerX + wheelOffset + i, centerY);
        Bresenham_LineDraw(centerX + wheelOffset + i, centerY, centerX + 2 * wheelOffset + i, centerY);
        Bresenham_LineDraw(centerX + 2 * wheelOffset + i, centerY, centerX + 2 * wheelOffset + i, centerY + wheelOffset);
        Bresenham_LineDraw(centerX + 2 * wheelOffset + i, centerY + wheelOffset, centerX + wheelOffset + i, centerY + wheelOffset);

        // Delay to control the animation speed
        delay(10);
    }

    getch();
    closegraph();
    return 0;
}
