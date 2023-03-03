/* Program to implement insertion sort using C programming language */
#include<stdio.h>
#include<conio.h>

int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int i, j, arr[size], small;
    printf("Enter %d numbers which are to be sorted : ", size);
    for(i=0; i<size; i++)
        scanf("%d", &arr[i]);

    for(i=1; i<size; i++){
        small = arr[i];
        for(j=i-1; j>=0 && arr[j]>small; j--)
            arr[j+1] = arr[j];
        arr[j+1] =small;
    }

    printf("The sorted numbers are : ");
    for(i=0; i<size; i++)
        printf("%d  ", arr[i]);
}