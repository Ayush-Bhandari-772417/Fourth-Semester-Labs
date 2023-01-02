#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

struct list{
	int info;
	struct list *next;
};

typedef struct list node;

node* start=NULL;

void f_insert();
void e_insert();
void m_insert();

void f_delete();
void e_delete();
void m_delete();

void traverse();
void search();
void destroy();

void menu();

void main() {
    printf("\n\n\n\t 1. Insert at first ");
    printf("\n\t 2. Insert at last");
    printf("\n\t 3. Insert at specified positon ");
    printf("\n\t 4. Delete from first ");
    printf("\n\t 5. Delete from last ");
    printf("\n\t 6. Delete from specific position");
    printf("\n\t 7. Display all values");
    printf("\n\t 8. Search an item");
    printf("\n\t 9. Delete list");
    printf("\n\t 10. Exit");
    menu();
}
void menu(){
    int ch;
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            f_insert();
            break;
        case 2:
            e_insert();
            break;
        case 3:
            m_insert();
            break;
        case 4:
            f_delete();
            break;
        case 5:
            e_delete();
            break;
        case 6:
            m_delete();
            break;
        case 7:
            traverse();
            break;
        case 8:
            search();
            break;
        case 9:
            destroy();
            break;
        case 10:
            printf("\n\n\t Program terminated successfully !!!");
            break;
        default:
            printf("\t\t Please enter the correct choice!!! \n");
        }
        if(ch==10)
            break;
    }
}
void f_insert(){
	node *item = (node*)malloc(sizeof(node));
    printf("Enter data to input: ");
    scanf("%d", &item->info);
    if(start==NULL){
        item->next=NULL;
        start=item;
    }
    else{
        item->next=start;
        start=item;
    }
}
void e_insert(){
	node *item = (node*)malloc(sizeof(node));
    printf("Enter data to input: ");
    scanf("%d", &item->info);
    if(start==NULL){
        item->next=NULL;
        start=item;
    }
    else{
        node *temp;
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = item;
        item->next = NULL;
    }
}
void m_insert(){
	int n, count=1;
    node *item, *temp;
    item=(node*)malloc(sizeof(node));
    printf("Enter the positon : ");
    scanf("%d", &n);
    printf("Enter data to input : ");
    scanf("%d", &item->info);
    temp=start;
    if(start==NULL)
    	printf("Empty list");
    else if(n==1){
    	item->next=start;
    	start=item;
    }
    else{
    	while (temp->next!=NULL){
        	if(count==(n-1))
        		break;
            temp=temp->next;
            count++;
        }
        printf("\n %d \t %d \n",count, n);
		if(count==(n-1)){
			item->next=temp->next;
			temp->next=item;
		}
		else
		   	printf("Position undefined");
	}
}

void f_delete(){
	node *ptr;
	if(start==NULL)
		printf("Empty list");
	else if(start->next==NULL){
		printf("The deleted data is: %d", start->info);
		free(start);
		start=NULL;
	}
    else{
        ptr=start;
        start=start->next;
        printf("The deleted data is : %d", ptr->info);
        free(ptr);
    }
}
void e_delete(){
	node *ptr, *loc;
    if(start==NULL)
        printf("Empty list");
    else if(start->next==NULL){
        printf("Deleted data is : %d", start->info);
        free(start);
        start=NULL;
    }
    else{
        ptr=start;
        while (ptr->next != NULL)
        {
            loc = ptr;
            ptr = ptr->next;
        }
        loc->next = NULL;
        printf("The deleted data is: %d", ptr->info);
        free(ptr);
    }
}
void m_delete(){
    node *ptr, *temp;
	int n, count=0;
    if(start==NULL)
        printf("Empty list");
    else{
        printf("Enter the positon : ");
        scanf("%d", &n);
        ptr=start;
        
        if((start->next==NULL) && (n==1)){
        	printf("The deleted item is: %d", start->info);
        	free(start);
        	start=NULL;
        }
		else if(n==1){
			ptr=start;
			start=start->next;
			printf("The deleted item is : %d", ptr->info);
			free(ptr);
		}
        else{
        	while(ptr != NULL){
				count++;
				printf("\n%d\t%d\n",count,n);
				if(count==n)
					break;
				temp=ptr;
            	ptr=ptr->next;
            }
            if(count==n){
            	temp->next=ptr->next;
            	printf("Deleted item is: %d", ptr->info);
            	free(ptr);
            }
            else
               	printf("Invaid position");
        }
    }
}

void traverse(){
	node *temp;
    temp=start;
    if(temp==NULL)
        printf("Empty list");
    else{
    	printf("Elements of list are :- ");
    	while (temp != NULL){
    		printf("\n\t %d", temp->info);
            temp=temp->next;
        }
    }
}
void search(){
	node *temp;
    int key, count=1;
    printf("Enter element to search : ");
    scanf("%d", &key);
    temp=start;
    while(temp != NULL){
        if(temp->info==key)
            break;
        else{
            count++;
            temp=temp->next;
        }
    }
    if(start==NULL)
        printf("List is empty");
    else if(temp==NULL)
        printf("Element not found");
    else
        printf("Element found and the position is %d", count);
}
void destroy(){
	node *temp;
    if(start==NULL)
        printf("Empty list");
    else{
        while (start != NULL)
        {
            temp=start;
            start=start->next;
            free(temp);
        }
    }
}
