//
// Created by Marius on 7/29/2017.
//


#include <iostream>
#include <cstdlib>

int ControlNumber(std::string number){
    if(number.length() != 9){
        return -1;
    }

    int sum = 0;
    for(int i = 1 ; i <= number.length(); i++){
        sum += (number[i - 1] -'0') * i;

    }

    return sum;
};

int CheckDigit(int controlNumber){
    if(controlNumber % 11 == 10){
        return 'X';
    }

    return controlNumber % 11;
}

int main(){

    int controlNumber = ControlNumber("408873104");
    std::cout << CheckDigit(controlNumber);
}
