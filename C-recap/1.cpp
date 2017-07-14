//
// Created by Marius on 6/29/2017.
//

/*Read a sequence of maximum 1000 numbers, from an input file. Each number is written per line. The sequence will be
 * stored in an array. Sort this array using a sorting algorithm of your choosing, and print it on the screen.
 * Use the appropriate functions : fopen, fgets, fclose, atoi*/

#include <stdio.h>
#include <stdlib.h>

void SortNumbers(int mArray[1000], int k) {
    int i, j;

    for (i = 0; i < k; i++) {
        for (j = i + 1; j < k; j++) {

            if (mArray[i] > mArray[j]) {
                mArray[i] = mArray[i] +  mArray[j];
                mArray[j] = mArray[i] - mArray[j];
                mArray[i] = mArray[i] - mArray[j];
            }
        }
    }
}

bool ReadNumbersFromFile(const char *name) {
    FILE *fp = fopen(name, "r");

    if (fp != NULL) {
        char mNumbers[10]; //maximum 10 digits
        int mArray[1000];
        int k = 0;

        while (fgets(mNumbers, sizeof(mNumbers), fp) != NULL) {
            mArray[k++] = atoi(mNumbers);
            SortNumbers(mArray, k);
        }
        if (feof(fp)) {
            printf("End of file reached\n");

            for (int i = 0; i < k; i++) {
                printf("%d\t", mArray[i]);
            }
            fclose(fp);
            return true;
        }
    fclose(fp);
    } else {
        perror("Error reading from file !");
        return false;
    }
    return false;
}

int main() {
    ReadNumbersFromFile("C:\\Users\\Marius\\Desktop\\CTraining\\text.txt");
    return 0;
}