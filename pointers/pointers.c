#include <stdio.h>

int main(){
    int x = 10;
    int* pX = &x;
    int y = *pX;
    printf("Value: %d\n", x);
    printf("Pointer: %p\n", pX);
    printf("Value by the pointer: %d\n", y);
}
