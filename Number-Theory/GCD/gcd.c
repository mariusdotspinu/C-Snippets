#include<stdio.h>
void gcd (int a, int b){
    if (a == 0 && b == 0){
        printf("Wrong input");
    }
    else{
        int r = 0;
        while (b != 0){
            r = a % b;
            a = b;
            b = r;
        }
        printf("%d", a);
    }
}

int main(void){
    gcd(-23,6);
}
