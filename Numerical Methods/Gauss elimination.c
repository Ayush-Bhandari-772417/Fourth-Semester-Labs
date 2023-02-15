#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int n, i, j, k;
	float a[20][20], x[20], sum=0, ratio;
	/* Input section */
	printf("Enter the number of unknowns i.e. size of coefficient matrix (n) : ");
	scanf("%d", &n);
	printf("Enter the elements a[i][j] of the augmented matrix [A:C] : ");
	for(i=1; i<=n; i++){
		for(j=1; j<=n+1; j++){
			printf("a[%d][%d]: ",i,j);
			scanf("\t%f", &a[i][j]);
		}
	}
	/* Apply Gauss Elimination Method */
	for(i=1; i<=n-1; i++){
		if(a[i][i] == 0){
			printf("Mathematical error");
			exit(0);
		}
	}
	/* Forward elimination*/
	for(j=1; j<=n+1; j++){
		for(i=1; i<=n; i++){
			if(i>j){
				ratio = a[i][j] / a[j][j];
				for(k=1; k<=n+1; k++){
						a[i][k] = a[i][k] - (ratio * a[j][k]);
				}
			}
		}
	}
	/* Apply backward substitution */
	if((a[n][n]==0) && (a[n][n+1]==0)){
		printf("The system has infinite solutions and so the system is consistent");
		exit(0);
	}
	if((a[n][n]==0) && (a[n][n+1]!=0)){
		printf("The system has no solutions and so it is inconsistent");
		exit(0);
	}
	if((a[n][n]!=0) && (a[n][n+1]!=0)){
		printf("The system has unique solution and the system is consistent");
	}
	/* Backward substitution */
	x[n] = a[n][n+1] / a[n][n];
	for(i=n-1; i>=1; i--){
		sum = 0;
		for(j=i+1; j<=n; j++){
			sum = sum + a[i][j]*x[i];
		}
		x[i] = (a[i][n+1]-sum) / a[i][i];
	}
	/* Display the approximate solution of the system */
	printf("The required solution is as follows : \n");
	for(i=1; i<=n; i++){
		printf("x[%d] = %0.6f \n", i, x[i]);
	}
	getch();
	return 0;
}
