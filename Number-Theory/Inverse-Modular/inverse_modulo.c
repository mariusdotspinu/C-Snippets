#include"euclidean.h"
#include<stdlib.h>
#include<stdio.h>

void get_inverse_modulo(int a, int m){
  if(gcd(a, m) != 1){
    printf("No integer solutions !");
  }
  else{
    int alfa = extended_gcd(a, m);
    printf("%d ^ -1 mod %d = %d", a, m, (alfa % m));
  }
}

int main(int argc, char* argv[]){

  if(argc != 3 || atoi(argv[2]) < 1){
    printf("Wrong input");
  }
  else{
    int a = atoi(argv[1]);
    int m = atoi(argv[2]);
    
    get_inverse_modulo(a, m);
  }
  
}
