#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int *int_ptr;
	int_ptr = (int *) malloc(2);
	printf("Enter first integer: ");
	int a;
	scanf("%d",&a);
	printf("Enter second integer: ");
	int b;
	scanf("%d",&b);
	printf("Original values: 1st= %d 2nd= %d\n",a,b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("Swapped values: 1st = %d 2nd = %d\n",a,b);
	free(int_ptr);
	return 0;
}


