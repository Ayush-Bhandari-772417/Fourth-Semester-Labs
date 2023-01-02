#include <stdio.h>
#define maxsize 5

void enqueue();
void dequeue();
void display_all();
void display_front();
void display_rear();

int front = 0, rear = -1, queue[maxsize];

void main() {
    int ch;
    printf("\n\n\n\t 1. Enqueue operation ");
    printf("\n\t 2. Dequeue operation ");
    printf("\n\t 3. Display all elements ");
    printf("\n\t 4. Display front element ");
    printf("\n\t 5. Display rear element ");
    printf("\n\t 6. Exit");
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display_all();
            break;
        case 4:
            display_front();
            break;
        case 5:
            display_rear();
            break;
        case 6:
            printf("\n\n\t Program terminated successfully !!!");
            break;
        default:
            printf("\t\t Please enter the correct choice!!! \n");
        }
        if(ch==6)
            break;
    }
}

void enqueue() {
    int item;
    if(rear >= (maxsize-1))
        printf("The queue is full");
    else{
        printf("Enter the item: ");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
    }
}

void dequeue(){
    if(front > rear)
        printf("The queue is empty");
    else{
        printf("The dequeued item is: %d",queue[front]);
        front++;
    }
}

void display_all(){
    int i;
    if(front > rear)
        printf("The queue is empty");
    else{
    	printf("Data in the queue is:");
        for(i=front; i<=rear; i++)
            printf("\n\t %d", queue[i]);
    }
}

void display_front(){
    if(front > rear)
        printf("The queue is empty");
    else
        printf("The front element is: %d", queue[front]);
}
void display_rear(){
    if(front > rear)
        printf("The queue is empty");
    else
        printf("The rear element is: %d", queue[rear]);
}
