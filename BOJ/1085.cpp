#include <cstdio>



int main(){
    int x,y,w,h, distX, distY;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    if(x >= w-x) distX = w-x;
    else distX = x;

    if(y >= h-y) distY = h-y;
    else distY = y;
    
    if(distX >= distY) printf("%d\n", distY);
    else printf("%d\n", distX);
}