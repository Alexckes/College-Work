#include <stdio.h>
#include <stdlib.h>

int main ()
{
	printf("Enter the value for a: "); //prompts for user input
	int32_t a;
	scanf("%d",&a);
	printf("Enter the value for b: ");
	int32_t b;
	scanf("%d",&b);

	int32_t y = 0;
	int32_t x = 1;
	for(int32_t n = 1; n <= a; n++){ //each loop increases y by (a + b) ^ n - 1
		y = y + x;		//add x, or (a + b) ^ n - 1, to y
		x = x * (a + b);	//(a + b) ^ n == ((a + b)^n-1) * (a + b)
	}
	y = y + x;
	if(y != 1){//get rid of an extra 1 from performing y = y + x twice for n = 1
		y = y - 1;
	}
	printf("The answer is %d ",y);
	return 0;
}