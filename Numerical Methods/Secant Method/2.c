#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) 3*x+sin(x)-exp(x)

int main(){
	float x0,x1,x2,f0,f1,f2,e;
	int i=1, N;
	/* Input section */
	printf("Enter value of initial guesses x0 and x1: ");
	scanf("%f %f", &x0,&x1);
	printf("Enter absolute value of predefined error e: ");
	scanf("%f", &e);
	printf("Enter value of maximum number of iterations N: ");
	scanf("%d", &N);
	
	/* Appy Secant Method */
	printf("\n_________________________________________________________________________");
	printf("\n Iterations \tx0 \t\tx1 \t\tx2 \t\tf(x2)\n");
	printf("_________________________________________________________________________\n");
	do{
		f0=f(x0);
		f1=f(x1);
		if(f0==f1){
			printf("\n\t\t Mathematical error");
			exit(0);
		}
		x2=x1-(x1-x0)*f1/(f1-f0);
		f2=f(x2);
		printf("\t%d \t%f \t%f \t%f \t%f \n",i,x0,x1,x2,f2);
		x0=x1;
		x1=x2;
		i++;
		if(i>N){
			printf("\n\t\t The solution does not converge");
			exit(0);
		}
	}
	while(fabs(f2)>e);
	printf("\n_________________________________________________________________________\n");
	printf("\t\t The number of iterations required is: %d\n",i-1);
	printf("\t\t The approximate solution is: %0.8f \n",x2);
	printf("\t\t The absolute error is: %0.7f \n",fabs(x1-x0));
	printf("_________________________________________________________________________\n");
	getch();
	return 0;
}
