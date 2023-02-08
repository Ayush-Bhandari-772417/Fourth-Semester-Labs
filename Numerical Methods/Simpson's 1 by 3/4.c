//C-Source code for Compsite Simpson's 1/3 Rule
#include<stdio.h>
#include<math.h>
#include<conio.h>
#define f(x) exp(sin(x))
int main(){
	printf("Integrating f(x) = exp(sin(x)) by Simpson's 1/3 rule\n");
	int n, i;
	float x0,xn,h,k,fk,I=0.0;
	/* Input */
	printf("Enter the values of x0, xn, n : ");
	scanf("%f %f %d",&x0, &xn, &n);
	/* Calculation */
	h=(xn-x0)/n;
	I=f(x0)+f(xn);
	printf("\n Length of each interval = h = %f",h);
	printf("\n\n Table for functional values: \n");
	printf("\n\t\t   x \t\t   f(x)");
	printf("\n\t\t %f \t %f", x0, f(x0));
	for(i=1;i<=(n-1);i++){
		k=x0+i*h;
		fk=f(k);
		if((i%2)==0)
			I=I+2*fk;
		else
			I=I+4*fk;
		printf("\n\t\t %f \t %f", k, f(k));
	}
	printf("\n\t\t %f \t %f", xn, f(xn));
	I=I*h*1/3;
	printf("\n\n The approximate value of the integral is I = %0.8f \n", I);
	getch();
	return 0;
}
