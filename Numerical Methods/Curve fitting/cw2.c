#include<stdio.h>
#include<conio.h>
#include<math.h>
void main(){
	int n,i;
	float x[30],y[30],Y[30],sumx=0,sumx2=0,sumY=0,sumxY=0,b,A,a;
	printf("C Program for fitting Curves using the method of least squares\n");
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
	
	for(i=1;i<=n;i++)
		Y[i]=log(y[i]);
	
	/* Compute sums */
	for(i=1;i<=n;i++){
		sumx=sumx+x[i];
		sumx2=sumx2+x[i]*x[i];
		sumY=sumY+Y[i];
		sumxY=sumxY+x[i]*Y[i];
	}
	/* Compute a and b */
	b=(n*sumxY-sumx*sumY)/(n*sumx2-sumx*sumx);
	A=(sumY-b*sumx)/n;
	a=exp(A);
	/* Display the outcome */
	printf("The values of a and b are: a=%0.4f and b=%0.4f \n",a,b);
	printf("The fitted curve is y=%0.4f*e^(%0.4fx) \n",a,b);
	
	printf("______________________________________________________________\n\n");
	float val, xvar=4.5;
	val=a*exp(b*xvar);
	printf("The value of y at x=4.5 is: %f", val);
	printf("\n______________________________________________________________\n");
	getch();
}
