#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define SIZE 5
#define WIDTH 100
#define HEIGHT 50

class Stack {
    int top;
    int arr[SIZE];
public:
    Stack() {
        top = -1;
    }
    bool isEmpty();
    bool isFull();
    void push(int x);
    int pop();
    void display();
};

bool Stack::isEmpty() {
    return (top < 0);
}

bool Stack::isFull() {
    return (top >= SIZE - 1);
}

void Stack::push(int x) {
    if (isFull()) {
        cout << "Stack overflow" << endl;
    }
    else {
        arr[++top] = x; 
        cout << "Pushed " << x << " to the stack" << endl;
    }
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    else {
        int x = arr[top--];
        cout << "Popped " << x << " from the stack" << endl;
        return x;
    }
}

void Stack::display() {

    cleardevice();

    rectangle(100, 100, 100 + WIDTH, 100 + SIZE * HEIGHT);

    for (int i = 1; i < SIZE; i++) {
        line(100, 100 + i * HEIGHT, 100 + WIDTH, 100 + i * HEIGHT);
    }

    settextstyle(0, 0, 2);
    for (int i = 0; i <= top; i++) {
        char s[10];
        sprintf(s, "%d", arr[i]);
        setfillstyle(SOLID_FILL, RED);
        bar(101, 101 + i * HEIGHT, 99 + WIDTH, 99 + (i + 1) * HEIGHT);
        setcolor(15);
        outtextxy(150, 125 + i * HEIGHT, s);
    }

    if (!isEmpty()) {
        line(250, 125 + top * HEIGHT, 300, 125 + top * HEIGHT);
        line(300, 125 + top * HEIGHT, 300, 75); 
        line(300, 75, 280, 95);
        line(300, 75, 320, 95); 
        outtextxy(325, 70, "TOP");
    }

}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"");

    Stack s;

   char ch; 
   do {
      cout << "Enter your choice: \n";
      cout << "1. Push an element \n";
      cout << "2. Pop an element \n";
      cout << "3. Exit \n";
      cin >> ch; 
      switch(ch) {
         case '1': 
            int x;  
            cout << "Enter an integer to push: \n";
            cin >> x; 
            if (cin.fail()) { 
               cout << "Invalid input" << endl;
               cin.clear();
               cin.ignore(1000,'\n'); 
            }
            else {
               s.push(x);
               s.display();
               delay(1000); 
            }
            break;
         case '2':
            s.pop(); 
            s.display();
            delay(1000);
            break;
         case '3':
            cout << "BYE" << endl;
            break;
         default:
            cout << "Invalid choice" << endl;
      }
   } while (ch != '3');
   delay(10000);
   closegraph();

   return 0;
}

