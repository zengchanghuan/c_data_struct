#include <stdio.h>
#include <math.h>
#define MAX 20

// array of items on which linear search will be conducted.
int intArray[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

void printline(int count){
    int i;
    for(i=0;i <count-1;i++){
        printf("=");
    }
    printf("=\n");
}
int find(int data){
    int lowerBound = 0;
    int upperBound = MAX -1;
    int midPoint = -1;
    int comparisons = 0;
    int index = -1;
    while(lowerBound <= upperBound){
        printf("Comparison %d\n" , (comparisons +1) ) ;
        printf("lowerBound : %d, intArray[%d] = %d\n",
               lowerBound,lowerBound,intArray[lowerBound]);
        printf("upperBound : %d, intArray[%d] = %d\n",
               upperBound,upperBound,intArray[upperBound]);
        comparisons++;
        // probe the mid point
        midPoint = lowerBound +
                   round((double)(upperBound - lowerBound)
                         / (intArray[upperBound] - intArray[lowerBound])
                         *  (data - intArray[lowerBound]));
        printf("midPoint = %d\n",midPoint);
        // data found
        if(intArray[midPoint] == data){
            index = midPoint;
            break;
        } else {
            // if data is larger
            if(intArray[midPoint] < data){
                // data is in upper half
                lowerBound = midPoint + 1;
            }
                // data is smaller
            else{
                // data is in lower half
                upperBound = midPoint -1;
            }
        }
    }
    printf("Total comparisons made: %d" , comparisons);
    return index;
}
void display(){
    int i;
    printf("[");
    // navigate through all items
    for(i=0;i<MAX;i++){
        printf("%d ",intArray[i]);
    }
    printf("]\n");
}
int main(){
    printf("Input Array: ");
    display();
    printline(50);

    //find location of 1
    int location = find(55);

    // if element was found
    if(location != -1)
        printf("\nElement found at location: %d" ,(location+1));
    else
        printf("Element not found.");
}