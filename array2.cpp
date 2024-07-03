#include <graphics.h>
#include <iostream>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int x = 100;
    int y = 100;
    int width = 50;
    int height = 50;

    for (int i = 0; i < n; i++) {
        setcolor(WHITE);
        rectangle(x + i * width, y, x + (i + 1) * width, y + height);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x + i * width + 1, y + 1, WHITE);
        setcolor(WHITE);
        rectangle(x + i * width, y, x + (i + 1) * width, y + height);
        delay(500);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x + i * width + 1, y + 1, WHITE);
        char buffer[10];
        sprintf(buffer, "%d", arr[i]);
        outtextxy(x + i * width + 20, y + height / 2 - 10, buffer);
    }

    cout << "Enter an index to delete: ";
    int index;
    cin >> index;

    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    cleardevice();

    for (int i = 0; i < n; i++) {
        setcolor(WHITE);
        rectangle(x + i * width, y, x + (i + 1) * width, y + height);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x + i * width + 1, y + 1, WHITE);
        setcolor(WHITE);
        rectangle(x + i * width, y, x + (i + 1) * width, y + height);
        delay(500);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x + i * width + 1, y + 1, WHITE);
        delay(500);

        char buffer[10];
        sprintf(buffer, "%d", arr[i]);
        outtextxy(x + i * width + 20, y + height / 2 - 10, buffer);
    }

    getch();
    closegraph();
    return 0;
}

