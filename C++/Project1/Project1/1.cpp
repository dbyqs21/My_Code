#include <stdio.h>

int  getResult(int * array, int length, int c)
{
	int result = 0;
	for (int k = 0; k < length; k++)
	{
		if (c > 0)
		{
			for (int i = 0; i < length;i++)
			if (c == array[i])
			{
				result++;
				break;
			}
	
			else
			result += getResult(array, length, c - array[k]);
		}
		if (c <= 0)
		{
			break;
		}
	}
	return result;
}

void main()
{
	int a[2] = { 1, 2 };
	printf("%d", getResult(a, 2, 5));
	getchar();
}