/* Parabolic Fit By Least Square Method */                                                        
#include <stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int n,i,j,k;
    float x[30]={0.0},y[30]={0.0},sumx=0.0,sumx2=0.0,sumx3=0.0,sumx4=0.0,sumy=0.0,sumxy=0.0,sumx2y=0.0,ratio,a[5][5]={0.0},m[4]={0.0};
    printf("\t C Program for Parabolic Fit By Using Least Squares Method\n\n");
    printf("Enter no. of data points (n): ");
    scanf("%d", &n);
    printf("\n Enter the respective values of variables x and y in pairs:\n");
    for(i=1;i<=n;i++)
        scanf("%f%f",&x[i],&y[i]);
    printf("\nThe table of values entered is as follows:\n");
    printf("   x\t\t   y\n");
    for(i=1;i<=n;i++)
        printf(" %0.4f\t\t%0.4f\n",x[i],y[i]);
    for(i=1;i<=n;i++){
        sumx += x[i];
        sumx2 += x[i]*x[i];
        sumx3 += x[i]*x[i]*x[i];
        sumx4 += x[i]*x[i]*x[i]*x[i];
        sumy += y[i];
        sumxy += x[i]*y[i];
        sumx2y += x[i]*x[i]*y[i];
    }

    a[1][1] = n;
    a[1][2] = sumx;
    a[1][3] = sumx2;
    a[1][4] = sumy;
    a[2][1] = sumx;
    a[2][2] = sumx2;
    a[2][3] = sumx3;
    a[2][4] = sumxy;
    a[3][1] = sumx2;
    a[3][2] = sumx3;
    a[3][3] = sumx4;
    a[3][4] = sumx2y;
    n=3;
    
    printf("\nIn Matrix Form:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            printf("\t%f",a[i][j]);
        }
        printf("\n");
    }
    
	/* Apply Gauss Jordan Method */
	for(i=1; i<=n-1; i++)
		if(a[i][i] == 0){
			printf("Mathematical error");
			exit(0);
		}
	
	/* Making unit matrix */
	for(j=1; j<=n; j++)
		for(i=1; i<=n; i++)
			if(i!=j){
				ratio = a[i][j] / a[j][j];
				for(k=1; k<=n+1; k++)
					a[i][k] = a[i][k] - ratio * a[j][k];
			}
	
	/* Check the consistency */
	if((a[n][n]==0) && (a[n][n+1]==0)){
		printf("\nThe system of equations has infinite solutions and curve cannot be fitted");
		exit(0);
	}
	if((a[n][n]==0) && (a[n][n+1]!=0)){
		printf("\nThe system of equations has no solutions and curve cannot be fitted");
		exit(0);
	}
	/* Calculate values of variables */
	for(i=1; i<=n; i++)
		m[i] = a[i][n+1] / a[i][i];
    
    printf("\n\nThe values of a, b and c are: a = %0.4f, b = %0.4f and c = %0.4f",m[1],m[2],m[3]);
    printf("\nThe fitted parabola is: y = %0.4f + %0.4fx + %0.4fx^2 \n",m[1],m[2],m[3]);
    return 0;
}
