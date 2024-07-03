#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}
void drawNode(int x, int y, int r, int val) {
    setcolor(15);
    circle(x, y, r);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x, y, 15);
    setcolor(15);
    char s[10];
    sprintf(s, "%d", val);
    outtextxy(x - r/2, y - r/4, s);
    delay(1000);
}
void drawLine(int x1, int y1, int x2, int y2) {
    setcolor(14);
    line(x1, y1, x2, y2);
    delay(1000);
}
void drawTree(Node* root, int x, int y, int level) {
    if (root == NULL) {
        return;
    }
    int r = 20;
    int hDist = 90 * pow(2, 4 - level);
    int vDist = 90;
    double angle = atan2(vDist, hDist) * 180 / M_PI;
    drawNode(x, y, r, root->data);
    if (root->left != NULL) {
        int x1 = x - hDist * sin(angle * M_PI / 180);
        int y1 = y + vDist * cos(angle * M_PI / 180);
        drawLine(x - r/2 , y + r/2 , x1 + r/2 , y1 - r/2 );
        drawTree(root->left , x1 , y1 , level + 1);        
     }
     if (root->right != NULL) {
         int x2 = x + hDist * sin(angle * M_PI / 180);
         int y2 = y + vDist * cos(angle * M_PI / 180);
         drawLine(x + r/2 , y + r/2 , x2 - r/2 , y2 - r/2 );
         drawTree(root->right , x2 , y2 , level + 1);   
     }
     
}
int main()
{
     int gd = DETECT , gm;
     initgraph(&gd , &gm , NULL);
     int n;
     cout << "Enter number of nodes: ";
     cin >> n;
     Node* root = NULL;  
     cout << "Enter " << n << " values: ";
     for (int i = 0; i < n; i++) {
         int val; 
         cin >> val; 
         root = insert(root , val); 
     }
     drawTree(root , getmaxx()/2 , 50 , 1); 
     getch(); 
     closegraph(); 
     return 0;
}

