#include<stdio.h>
#include<math.h>
#define PI 3.14159

int main()
{
	int n=100;
	double a=0,b=2*PI,h,x;
	h=(b-a)/n;
		printf("\"x\",\"sin(x)\"\n");
	for(int i=0;i<=n;i++){
	x=x+h;
	printf("%lf,%lf\n",x,sin(x));
}
return 0;
}
