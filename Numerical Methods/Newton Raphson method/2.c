#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) x*x-3*x+2
#define df(x) 2*x-3

void main(){
    int N, step=1;
    float x0, x1, f0, f1, e, df0;
    /*Input*/
    printf("Enter value of initial guess x0: ");
    scanf("%f", &x0);
    printf("Enter value of tolerable error e: ");
    scanf("%f", &e);
    printf("Enter number of maximum iteration N: ");
    scanf("%d", &N);
    printf("\nStep \t x0 \t\t f(x0) \t\t df(0) \t\t x1 \t\t f(x1) \n");
    do{
        f0=f(x0);
        df0=df(x0);
        if(df0==0.0){
            printf("Mathematical error");
            exit(0);
        }
        x1=x0-f0/df0;
        f1=f(x1);
        printf("\n%d \t%f \t%f \t%f \t%f \t%f",step,x0,f0,df0,x1,f1);
        x0=x1;
        step++;
        if(step>N){
            printf("\n\n\t Solution does not converge");
            exit(0);
        }
    }
    while(fabs(f1)>e);
    printf("\n\n\t The approximate root is: %f", x1);
    getch();
}
