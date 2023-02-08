//C-Source code for Compsite Simpson's 3/8 Rule
#include<stdio.h>
#include<math.h>
#include<conio.h>
#define f(x) pow(sin(x),0.5)
int main(){
	printf("Integrating f(x) = pow(sin(x),0.5) by Simpson's 3/8 rule\n");
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
		if((i%3)==0)
			I=I+2*fk;
		else
			I=I+3*fk;
		printf("\n\t\t %f \t %f", k, f(k));
	}
	printf("\n\t\t %f \t %f", xn, f(xn));
	I=I*h*3/8;
	printf("\n\n The approximate value of the integral is I = %0.8f \n", I);
	getch();
	return 0;
}
