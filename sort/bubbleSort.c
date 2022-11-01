#include <stdio.h>
#include <stdbool.h>

#define MAX 7

int intArray[MAX] = {4, 6, 3, 2, 1, 9, 7};

void printline(int count) {
    int i;
    for (i = 0; i < count - 1; i++) {
        printf("=");
    }
    printf("=\n");
}

void display() {
    int i;
    printf("[");
    // navigate through all items
    for (i = 0; i < MAX; i++) {
        printf("%d ", intArray[i]);
    }
    printf("]\n");
}

void bubbleSort() {
    int temp;
    int i, j;
    bool swapped = false;
    // loop through all numbers
    for (i = 0; i < MAX - 1; i++) {
        swapped = false;
        // loop through numbers falling ahead
        for (j = 1; j < MAX - i; j++) {
            printf("     Items compared: [ %d, %d ]\n", intArray[j - 1], intArray[j]);
            // check if next number is lesser than current no
            //   swap the numbers.
            //  (Bubble up the highest number)
            if (intArray[j - 1] > intArray[j]) {
                temp = intArray[j - 1];
                intArray[j - 1] = intArray[j];
                intArray[j] = temp;
                swapped = true;
            }
        }
        // if no number was swapped that means
        //   array is sorted now, break the loop.
        if (!swapped) {
            break;
        }
        printf("Iteration %d#: ", (i + 1));
        display();
    }
}

int main() {
    printf("Input Array: ");
    display();
    printline(50);
    bubbleSort();
    printf("Output Array: ");
    display();
    printline(50);
}