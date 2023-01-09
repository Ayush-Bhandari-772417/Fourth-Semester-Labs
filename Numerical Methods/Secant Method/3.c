#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) x*exp(x)-cos(x)

int main(){
	float x0,x1,x2,f0,f1,f2,e;
	int Iteration=1, N;
	/* Input section */
	printf("Enter value of initial guesses x0 and x1: ");
	scanf("%f %f", &x0,&x1);
	printf("Enter absolute value of predefined error e: ");
	scanf("%f", &e);
	printf("Enter value of maximum number of iterations N: ");
	scanf("%d", &N);
	
	/* Appy Secant Method */
	printf("\n___________________________________________________________");
	printf("\nIterations \tx0 \t\tx1 \t\tx2 \t\tf(x2)\n");
	printf("_____________________________________________________________\n");
	do{
		f0=f(x0);
		f1=f(x1);
		if(f0==f1){
			printf("\n\t\t Mathematical error");
			exit(0);
		}
		x2=x1-(x1-x0)*f1/(f1-f0);
		f2=f(x2);
		printf("\t%d \t%f \t%f \t%f \t%f \n",Iteration,x0,x1,x2,f2);
		x0=x1;
		f0=f1;
		x1=x2;
		f1=f2;
		Iteration++;
		if(Iteration>N){
			printf("\n\t\t The solution does not converge");
			exit(0);
		}
	}
	while(fabs(f2)>e);
	printf("\n___________________________________________________________\n");
	printf("\n\t\t The approximate solution is: %0.8f \n",x2);
	getch();
}
