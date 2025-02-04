#include<stdio.h> 
#include<math.h> 

double fun(double x) {
  return (x*x) - (5*x) - 21;
}
int main ()  {
   double x1,x2,x3;
   int itterations;
	printf("Enter the value of [x1,x2]:");
	scanf("%lf %lf",&x1,&x2);
	

	printf("\nEnter the number of itterations:");
	scanf("%d",&itterations);

	int count = 1;

  while(count <= itterations) { 
 	x3 = (x1 * fun(x2)) - x2 * fun(x1) / (fun(x1) - fun(x2));
	printf("Itteration: %d ,x1: %2.lf x2: %2.lf x3:%2.lf \n",count,x1,x2,x3);
	
if(fun(x3) < 0) { 
	x1 = x3;
}

else { 
x2 = x3;
} 
count++;
}
printf("Approximate root:%2.lf\n",x3);
return 0; 
}

 
