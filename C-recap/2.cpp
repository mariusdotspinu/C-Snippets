//
// Created by Marius on 6/29/2017.
//

/*Working with pointers. Here's a matrix, n x m. Draw a circle with a given centre, and a certain ray. The function
 * that draws the circle will get a pointer as parameter, to the first element of the matrix.
 *
 * 1 - positive
 * 0 - otherwise
 *
 *
 * D(P1,P2) = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)) */

#define MATRIX_HEIGHT 6
#define MATRIX_WIDTH 5

#include <stdio.h>
#include <math.h>

int matrix[MATRIX_HEIGHT][MATRIX_WIDTH];

int EuclideanDistance(int x1, int x2, int y1, int y2){
    return (int)ceil(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

void Circle(int *ptr, int cx, int cy, int ray) {

    for (int i = 0; i < MATRIX_HEIGHT; i++) {
        for (int j = 0; j < MATRIX_WIDTH; j++) {
            if (EuclideanDistance(j, cx, i, cy) == ray) {
                *(ptr + sizeof(ptr) * i + j + i) = 1;
            } else {
                *(ptr + sizeof(ptr) * i + j + i) = 0;
            }
        }
    }

}

int main(){
    Circle(&matrix[0][0], 2, 2, 2);

    for(int i = 0; i < MATRIX_HEIGHT; i++){
        for(int j = 0 ; j < MATRIX_WIDTH; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

