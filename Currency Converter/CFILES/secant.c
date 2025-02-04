#include<stdio.h>
#include<math.h>

double fun(double x) { 
	return  (x*x*x) + x - 6; //x3+ x 6=0
}

int main() {
	double x1,x2,x3;
	int itterations;
	printf("Enter the assumed roots: ");
	scanf("%lf %lf",&x1,&x2);
	printf("\n Enter the number of itterations : ");
	scanf("%d",&itterations);

	int count = 1;

	while(count <= itterations) { 
		x3 = (x1 * fun(x2)) - x2 * fun(x1) / (fun(x1) - fun(x2));
		printf("Itteration: %d x1: %.3lf x2: %.3lf x3:%.3lf \n",count,x1,x2,x3);
		x1 = x2;
		x2 = x3;

		count++;
	}
	printf("Approximate roots: %.3lf\n",x3);
	return 0;
}

	
