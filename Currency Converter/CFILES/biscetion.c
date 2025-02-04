#include<stdio.h>
#include<math.h>

double fun(double x) { 
	return (x*x) - (4*x) - 21;
}

int main() { 
	double x1,x2,x3;
	int itteration;
	printf("Enter the assumed roots [x1,x2] : ");
	scanf("%lf %lf",&x1,&x2);
	printf("\n");
	printf("Enter the number of itterations: ");
	scanf("%d",&itteration);
	int count = 1;

	while(count <= itteration) { 
		x3 = (x1+x2) / 2;
		printf("Itteration : %d  x1 : %2.lf  x2 : %2.lf x3 : %2.lf \n" , count,x1,x2,x3);
		if(fun(x3) < 0) { 
		 x1 = x3;
		}
		else { 
			x2 = x3;
		}
		count++;
	}
	printf("Approximate root : %2.lf \n",x3); 
	return 0;
}

