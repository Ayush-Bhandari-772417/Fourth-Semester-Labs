#include<stdio.h>
#include<conio.h>

#define NO 8
void binsrch(int arr[], int beg, int end, int item);

int main(){
    int i, j, item, arr[NO], small;
    printf("Enter %d numbers : ", NO);
    for(i=0; i<NO; i++)
        scanf("%d", &arr[i]);

    for(i=1; i<NO; i++){
        small = arr[i];
        for(j=i-1; j>=0 && arr[j]>small; j--)
            arr[j+1] = arr[j];
        arr[j+1] =small;
    }

    printf("Enter no. to be seached : ");
    scanf("%d", &item);
    binsrch(arr, 0, NO, item);
}

void binsrch(int arr[], int beg, int end, int item){
    int mid, count=1;
    mid = (beg+end)/2;
    count++;
    while(beg<=end && item != arr[mid]){
        if(item < arr[mid])
            end =mid-1;
        else
            beg=mid+1;
        mid=(beg+end)/2;
        count++;
    }
    if(item==arr[mid]){
        printf("Search successful!!! \n It took %d iterations to find this item", count);
        printf("\n The position is %d",mid);
    }
    else
        printf("Search unsuccessful!!!");
}