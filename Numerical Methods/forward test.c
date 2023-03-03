#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x, y) (-1.2 * y + 7 * exp(0.3 * x))

int main(){
	float x0,y0,xn,h,yn=0,k1,k2,k3,k4,k, t;
	int i,n;
	printf("\t C Program for RK-4 method \n");
	printf("For the function : (y*y-x*x)/(y*y+x*x) \n");
	printf("Enter Initial Conditions: x0 and y0: ");
	scanf("%f %f",&x0, &y0);
	printf("Enter the value calculation point xn = ");
	scanf("%f",&xn);
	printf("Enter the value of intervals required (h) = ");
	scanf("%f",&h);
	t=(xn-x0)/h;
	n=t;
	
	printf("\n x0\t\t y0\t\t yn\n");
	for(i=0;i<n;i++){
		k1 = h * (f(x0,y0));
		k2 = h * (f((x0+h/2),(y0+k1/2)));
		k3 = h * (f((x0+h/2),(y0+k2/2)));
		k4 = h * (f((x0+h),(y0+k3)));
		k = (k1+2*k2+2*k3+k4)/6;
		yn=y0+k;
		printf("%f \t%f \t%f \n",x0,y0,yn);
		y0=yn;
		x0=x0+h;
	}
	printf("\n The estimated value of y at x = %0.4f is y = %0.6f\n",xn,yn);
	getch();
	return 0;
}
