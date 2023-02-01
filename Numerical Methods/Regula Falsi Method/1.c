#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) 3*x+sin(x)-exp(x)
void main() {
    float x0,x1,x2,f0,f1,f2,e;
    int step = 1;
    while(1){
    	printf("Enter two initial guesses: ");
		scanf("%f %f", &x0, &x1);
		printf("Enter tolerable error: ");
		scanf("%f", &e);
		f0 = f(x0);
		f1 = f(x1);
		if((f0*f1)>0.0)
			printf("Incorrect initial guesses.\n");
		else
			break;
    }
	printf("\n_________________________________________________________________________________________________");
    printf("\n Step \tx0 \t\tx1 \t\tx2 \t\tf(x0) \t\tf(x1) \t\tf(x2) \n");
	printf("_________________________________________________________________________________________________\n");
    do {
        x2 = x0 - ((x1-x0)*f0)/(f1-f0);
        f2 = f(x2);
        printf("  %d \t%f \t%f \t%f \t%f \t%f \t%f\n",step,x0,x1,x2,f0,f1,f2);
        if((f0*f2)<0){
            x1=x2;
            f1=f2;
        }
        else{
            x0=x2;
            f0=f2;
        }
        step++;
    }
    while(fabs(f2)>e);
	printf("_________________________________________________________________________________________________\n");
    printf("\t\t\t\t The number of iterations required is: %d\n",step-1);
	printf("\t\t\t\t The approximate solution is: %0.8f \n",x2);
	printf("_________________________________________________________________________________________________\n");
    getch();
}
