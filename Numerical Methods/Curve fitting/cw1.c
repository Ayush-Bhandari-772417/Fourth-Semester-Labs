#include<stdio.h>
#include<conio.h>
#include<math.h>
void main(){
	int n,i;
	float x[30],y[30],sumx=0,sumx2=0,sumy=0,sumxy=0,a,b;
	printf(" C Program for fitting Regression line using least squares\n");
	printf("______________________________________________________________\n\n");
	/* Input section */
	printf("Enter the values of number of data points(N): ");
	scanf("%d",&n);
	printf("Enter the respective values of the variables x and y in pairs:\n");
	for(i=1;i<=n;i++)
		scanf("%f%f",&x[i],&y[i]);
	printf("______________________________________________________________\n");
	printf("\n The table of values you entered is as follows:\n");
	printf("    x \t\t\t   y \n");
	for(i=1;i<=n;i++)
		printf(" %0.4f \t\t%0.4f\n",x[i],y[i]);
	printf("______________________________________________________________\n\n");
	
	/* Compute sum */
	for(i=1;i<=n;i++){
		sumx=sumx+x[i];
		sumx2=sumx2+x[i]*x[i];
		sumy=sumy+y[i];
		sumxy=sumxy+x[i]*y[i];
	}
	/* Compute a and b */
	b=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
	a=(sumy-b*sumx)/n;
	/* Display the outcome */
	printf("The values of a and b are: a=%0.4f and b=%0.4f \n",a,b);
	printf("The equation of the best fit of the line is y=%0.4f+(%0.4fx) \n",a,b);
	
	printf("______________________________________________________________\n\n");
	float val, xvar=4.5;
	val=a+b*xvar;
	printf("The value of y at x=4.5 is: %f", val);
	printf("\n______________________________________________________________\n");
	getch();
}
