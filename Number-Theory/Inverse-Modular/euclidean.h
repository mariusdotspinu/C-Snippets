#ifndef EUCLIDEAN_H
#define EUCLIDEAN_H

struct v{
    int alfa, beta;
};

typedef struct v Vs;

void replace(Vs *a, Vs b);

int gcd(int a, int b);

Vs calculate_V1(Vs V, Vs V1, int q);

int extended_gcd (int a, int b);

#endif
