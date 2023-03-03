/* Program to implement merge sort using C programming language */
#include<stdio.h>
#include<conio.h>

void merge(int [], int [], int, int, int);
void msort(int [], int [], int , int);

int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    int i, j, arr[size], small, temp[size];
    printf("Enter %d numbers which are to be sorted : ", size);
    for(i=0; i<size; i++)
        scanf("%d", &arr[i]);

    msort(arr, temp, 0, size-1);

    printf("The sorted numbers are : ");
    for(i=0; i<size; i++)
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
}

void merge(int arr[], int temp[], int left, int mid, int right){
    int i, lend, no_element, tmpos;
    lend = mid - 1;
    tmpos = left;
    no_element = right - left + 1;
    while ((left <= lend) && (mid <= right)){
        if(arr[left] <= arr[mid]){
            temp[tmpos] = arr[left];
            tmpos ++;
            left++;
        }
        else{
            temp[tmpos] = arr[mid];
            tmpos++;
            mid ++;
        }
    }
    while (left <= lend){
        temp[tmpos] = arr[left];
        left++;
        tmpos++;
    }
    while ((mid <= right)){
        temp[tmpos] = arr[mid];
        mid ++;
        tmpos ++;
    }
    for(i=0; i<=no_element; i++){
        arr[right] = temp[right];
        right --;
    }
}