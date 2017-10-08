#include <stdio.h>
#include <string.h>

void main()
{
	int a = 3;
	int b = 4;
	printf("a=%d,b=%d", a, b);

	a = a^b;
	b = a^b;
	a = a^b;

	printf("a=%d,b=%d", a, b);
}