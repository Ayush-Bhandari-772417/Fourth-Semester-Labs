#include<stdio.h>
#include<conio.h>

#define NO 8

void merge(int arr[], int temp[], int left, int mid, int right);
void msort(int [], int [], int , int);

int main(){
    int i, j, arr[NO], small, temp[NO];
    printf("Enter %d numbers : ", NO);
    for(i=0; i<NO; i++)
        scanf("%d", &arr[i]);

    msort(arr, temp, 0, NO-1);

    printf("The sorted numbers are : ");
    for(i=0; i<NO; i++)
        printf("%d  ", arr[i]);
}

void msort(int arr[], int temp[], int left, int right){
    int mid;
    if(left < right){
        mid = (left + right) / 2;
        msort(arr, temp, left, mid);
        msort(arr, temp, mid+1, right);
        merge(arr, temp, left, mid+1, right);
}

void merge(int arr[], int temp[], int left, int mid, int right){



    int i, lend, noelement, tmpos;
    lend = mid - 1;
    tmpo;
}