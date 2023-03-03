/* Program to implement binary search in C programming language */
#include<stdio.h>
#include<conio.h>

void binsrch(int [], int, int, int);

int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int i, j, item, arr[size], small;
    char ch;
    printf("Enter %d numbers to implement binary search : ", size);
    for(i=0; i<size; i++)
        scanf("%d", &arr[i]);

    for(i=1; i<size; i++){
        small = arr[i];
        for(j=i-1; j>=0 && arr[j]>small; j--)
            arr[j+1] = arr[j];
        arr[j+1] = small;
    }

    printf("The sorted numbers are : ");
    for(i=0; i<size; i++)
        printf("%d  ", arr[i]);
    printf("\n");
    do{
        printf("\nEnter no. to be searched : ");
        scanf("%d", &item);
        binsrch(arr, 0, size, item);
        fseek(stdin,0,SEEK_END);
        printf("Do you want to search for another number (Y/N)? : ");
        scanf("%c",&ch);
    }
    while ((ch == 'Y') || (ch == 'y'));
}

void binsrch(int arr[], int beg, int end, int item){
    int mid, count=1;
    mid = (beg+end)/2;
    while(beg<=end && item != arr[mid]){
        if(item < arr[mid])
            end =mid-1;
        else
            beg=mid+1;
        mid=(beg+end)/2;
        count++;
    }
    if(item==arr[mid]){
        printf("Search successful!!! \n ");
        printf("It took %d iterations to find this item", count);
        printf("\n The position is %d \n\n",mid+1);
    }
    else
        printf("Search unsuccessful!!! \n\n");
}