#include <graphics.h>
#include <iostream>
using namespace std;

void drawElement(int x, int y, int w, int h, int i, int val) {
    setcolor(15);
    rectangle(x, y, x + w, y + h);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x + 1, y + 1, 15);
    setcolor(15); 
    delay(1000);
    char s1[10], s2[10];
    sprintf(s1, "%d", i);
    sprintf(s2, "%d", val);
    settextstyle(8, 0, 3);
    outtextxy(x + 5, y + 5, s1);
    outtextxy(x + w/2 - 10, y + h/2 - 10, s2);
}
void drawArray(int arr[], int n) {
    int w = getmaxx() / n - 10;
    int h = getmaxy() / 4;
    int x = 5;
    int y = getmaxy() / 2 - h / 2;
    for (int i = 0; i < n; i++) {
        drawElement(x, y, w, h, i, arr[i]);
        x += w + 10;
        delay(1000);
    }
}
int main()
{
     int gd = DETECT , gm;
     initgraph(&gd , &gm , NULL);
     setbkcolor(0); 
     int n;
     cout << "Enter size of array: ";
     cin >> n;
     int arr[n];
     cout << "Enter " << n << " values: "; 
     for (int i = 0; i < n; i++) {
         cin >> arr[i];      
     }
     drawArray(arr , n);  
     getch();  
     closegraph();
     return 0;
}

