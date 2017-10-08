// BigArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int  num1[4] = { 3, 4, 6, 5 };
	int num2[6] = { 9, 1, 2, 5, 8, 3 };
	printf("%d\n", sizeof(num1));
	int k = 5;
	int array[5];
	int cat = 0;
	int  cat2 = 0;


	int A = num1[0];
	int index = 0;
	for (int j = 1; j<4; j++)
	{
		if (num1[j] > A)
		{
			A = num1[j];
			index = j;
		}
	}

	int A2 = num2[0];
	int index2 = 0;
	for (int j = 1  ; j<6; j++)
	{
		if (num2[j] > A2)
		{
			A2 = num2[j];
			index2 = j;
		}
	}

	if (A >= A2)
	{
		num1[index] = -1;
		array[0] = A;
		cat = index;
	}
	else
	{
		num2[index2] = -1;
		array[0] = A2;
		cat2 = index2;
	}





	for (int i = 1; i<k; i++)
	{
		int max = num1[cat];
		for (int i1 = cat; i1<4; i1++)
		{
			if (num1[i1]>max)
			{
				max = num1[i1];
				index = i1;
			}
		}

		int max2 = num2[cat2];
		for (int i1 = cat2; i1<6; i1++)
		{
			if (num2[i1] > max2)
			{
				max2 = num2[i1];
				index2 = i1;
			}
		}


		if (max >= max2)
		{
			array[i] = max;
			num1[index] = -1;
			cat = index;
		}
		else
		{
			array[i] = max2;
			num2[index2] = -1;
			cat2 = index2;
		}
	}
	for (int k1= 0; k1 < 5; k1++)
	{
		printf("%d\n", array[k1]);
	}
	getchar();

	return 0;
}

