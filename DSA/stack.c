#include <stdio.h>
#include <conio.h>

int top = -1;
int max_size=5;
int stack[5];

void push();
void pop();
void display_all();
void display_top();

void main() {
    int ch;
    while(1) {
        printf("\n\n\n\t 1. Push operation");
        printf("\n\t 2. Pop operation");
        printf("\n\t 3. Display all elements");
        printf("\n\t 4. Display top element");
        printf("\n\t 5. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display_all();
            break;
        case 4:
            display_top();
            break;
        case 5:
            break;
        default:
        	printf("Wrong choice!!! Please make correct choice.");
        }
        if(ch==5)
        	break;
    }
}

void push() {
    int item;
    if(top == max_size)
        printf("The stack is full");
    else{
        printf("Enter the element: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("%d A new data is being added in stack",top);
    }
}

void pop() {
    int item;
    if(top == -1)
        printf("The stack cannot be popped any more because it's empty");
    else{
        printf("The popped element is %d", stack[top]);
        top--;
    }
}

void display_all(){
    int i;
	if (top == -1)
		printf("The stack is empty");
	else{
		printf("The elements of the stack are :");
		for(i=top; i>=0; i--)
        	printf("\n\t %d", stack[i]);
    }
}

void display_top(){
	if (top == -1)
		printf("The stack is empty");
	else
		printf("The top of the stack is : %d", stack[top]);
}
