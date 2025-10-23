#include <stdio.h>
#include <stdlib.h> 

int main ()
{
	printf("Enter the value for x: "); //prompts for user input
	float x;
	scanf("%f",&x);
	printf("Enter the value for a: ");
	int32_t a;
	scanf("%d",&a);

	float tpi = 2 * 3.14159265359; //approximation of 2pi
	float xpi = x; //xpi = x mod 2pi because in the sin function x would be the same as xpi. I am doing this then to make the calculation not reach the upper or lower float limits or be innacurate
	if(x < 0){ 
	while(xpi <= -tpi)
		xpi = xpi - tpi;
	}
	else{
	while(xpi >= tpi)
		xpi = xpi - tpi;
	}
	float y = 0;
	float ex = xpi; //== x^(2*0+1)
	float f = 1; //== (2*0+1)!
	int64_t s = -1; //(-1)^n
	for(int32_t n = 0; n < a; n++){//loops a times, looping makes the answer more accurate
		s = s * -1; //== (-1)^n
		if(n != 0){ //ex and f already start as x^(2*0+1) and (2*0+1)! respectively
		f = f * (2 * n);//== (2 * (n - 1) + 1)! * (2 * n) == (2 * n)!. f == (2 * (n - 1) + 1)!
		f = f * (2 * n + 1);//== (2 * n)! * (2 * n + 1) == (2 * n + 1)!. f == (2 * n)!
		ex = ex * xpi * xpi;//== x^(n-2)*x^2 == x^n. ex == x^(n-2)
		}
		y = y + s * (ex / f);//simplified equation
	}
	printf("sin(%f) = %f ",x,y);
	return 0;
}