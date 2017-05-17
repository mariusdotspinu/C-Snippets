#include<stdio.h>

int main(void){
    int *a;
    int b = 4;

    a = &b;
    
    printf("%d", *a);
}
