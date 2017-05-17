#include"euclidean.h"
#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
    if (a == 0 && b == 0){
       return -1;
    }
    else{
        int r = 0;
        while (b != 0){
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
}

void replace(Vs *a, Vs b){
    a->alfa = b.alfa;
    a->beta = b.beta;
}

Vs calculate_V1(Vs V, Vs V1, int q){
    Vs new_V1;

    new_V1.alfa = V.alfa - (q * V1.alfa);
    new_V1.beta = V.beta - (q * V1.beta);

    return new_V1;
}

int extended_gcd (int a, int b){

    Vs V, V0, V1;
    V0.alfa = 1;
    V0.beta = 0;

    V1.alfa = 0;
    V1.beta = 1;

    if (a == 0 && b == 0){
        printf("Wrong input");
    }

    else
    {

        int r = 0;
        int q = 0;
        
        while (b != 0){
            q = a / b;
            r = a % b;
            a = b;
            b = r;
            
            replace(&V, V0);
            replace(&V0, V1);
            replace(&V1, calculate_V1(V, V1, q));
        }

        V.alfa = V0.alfa;
        V.beta = V0.beta;

        return V.alfa;
    }
}
