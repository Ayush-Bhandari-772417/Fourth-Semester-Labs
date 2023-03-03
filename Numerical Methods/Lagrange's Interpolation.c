#include<stdio.h>
#include<conio.h>

int main(){
	int n,i,j,L=1;
	float x[50],y[50],xp,yp=0,p;
	printf("C Program for Lagrange's Interpolation \n");
	printf("Enter the number of given data points (n): ");
	scanf("%d",&n);
	printf("Enter the respective values of x and y in pairs (x,y): \n");
	for(i=1;i<=n;i++){
		scanf("%f %f",&x[i],&y[i]);
	}
	printf("\n The table of values that you entered is as follows:\n");
	printf("\tx  \ty \n");
	for(i=1;i<=n;i++){
		printf("\t%0.0f \t%0.0f \n",x[i],y[i]);
	}
	while(L==1){
		printf("\n\n Enter the value of independent variable x (say xp) at which value of y(say yp) is to be estimated : ");
		scanf("%f",&xp);
		yp=0;
		for(i=1;i<=n;i++){
			p=1;
			for(j=1;j<=n;j++){
				if(i!=j)
					p=p*(xp-x[j])/(x[i]-x[j]);
			}
			yp=yp+p*y[i];
		}
		printf("\n The estimated value of y at x=%0.0f is y=%0.4f",xp,yp);
		printf("\n\n Do you want to continue? \n If yes press 1 otherwise press any key : ");
		scanf("%d",&L);
	}
	getch();
	return 0;
}
