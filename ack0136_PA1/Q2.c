#include <stdio.h>
#include <stdlib.h>

int main ()
{
	printf("Enter the value for a: "); //prompts for user input
	int64_t a;
	scanf("%ld",&a);
	printf("Enter the value for b: ");
	int64_t b;
	scanf("%ld",&b);

	int64_t y = 0;
	int64_t x = 1; //starts at 1 bc otherwise 0! would be 0
	for(int64_t n = 1; n <= a; n++){ //each loop increases y by n! + b, starting at n = 0
		y = y + x; //add x to y
		x = x * n; //x becomes n!
	}
	y = y + a * b; // adds the summation of b
	printf("The answer is %ld ",y);
	return 0;
}