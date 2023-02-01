#include<stdio.h>
#include<conio.h>
void transfer(int n, char from, char to, char temp);

void main(){
    int n;
    char ch;
    do{
    	printf("\nEnter the no. of disks : ");
    	scanf("%d", &n);
    	transfer(n,'L','R','C');
    	fseek(stdin,0,SEEK_END);
		printf("\n\n Do you want to look steps for other number of disks (Y/N)? ");
		scanf("%c",&ch);
	}
	while((ch=='Y') || (ch=='y'));
	printf("\n\t Program ended successfully !!!");
}

void transfer(int n, char from, char to, char temp){
    if(n!=0){
        transfer(n-1,from,temp,to);
        printf("\n Move disk %d from %c to %c",n,from,to);
        transfer(n-1,temp,to,from);
    }
}
