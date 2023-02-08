#include<stdio.h>
#include<conio.h>

#define NO 8

int main(){
    int i, j, arr[NO], small;
    printf("Enter %d numbers : ", NO);
    for(i=0; i<NO; i++)
        scanf("%d", &arr[i]);

    for(i=1; i<NO; i++){
        small = arr[i];
        for(j=i-1; j>=0 && arr[j]>small; j--)
            arr[j+1] = arr[j];
        arr[j+1] =small;
    }

    printf("The sorted numbers are : ");
    for(i=0; i<NO; i++)
        printf("%d  ", arr[i]);
}