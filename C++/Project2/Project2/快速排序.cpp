#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void swap(ElementType *p, ElementType *q);
void insertion_sort(int Arr[], int N);
ElementType Median3(ElementType A[], int Left, int Right);
void quickSort(ElementType A[], int Left, int Right);

//快速排序
void quick_sort(ElementType A[], int N)
{
	quickSort(A, 0, N-1);
}

void quickSort(ElementType A[], int Left, int Right)
{
	int cutoff = 4;
	if (cutoff <= Right - Left)  //如果待排序的规模大于等于门限
	{
		ElementType Pivot = Median3( A,  Left,  Right);
		int i = Left;
		int j = Right - 1;
		while (true)
		{
			while (A[++i] < Pivot);
			while (A[--j]>Pivot);
			if (i < j)
			{
				swap(&A[i], &A[j]);
			}
			else
				break;
		}
		swap(&A[i], &A[Right - 1]);  //将主元换到中间的位置
		quickSort(A, Left, i - 1);
		quickSort(A, i+1, Right);
    }
	else
		insertion_sort(A + Left, Right - Left + 1);  //针对小规模问题，采用插入排序法
}

ElementType Median3(ElementType A[], int Left, int Right)
{
	int middle = (Left + Right) / 2;
	if (A[Left] > A[middle])
		swap(&A[Left], &A[middle]);
	if (A[Left] > A[Right])
		swap(&A[Left], &A[Right]);
	if (A[middle] > A[Right])
		swap(&A[middle], &A[Right]);
	swap(&A[middle], &A[Right - 1]);   //将主元换到最右边元素的前一个
	return A[Right - 1];
}


//插入排序:稳定，时间复杂读为O(n^2)，稳定，n小时较好。最好情况：顺序T=O(N);最坏情况：逆序T=O(N^2)；其平均时间复杂度下限为n^2
void insertion_sort(ElementType Arr[], int N)
{
	for (int i = 1; i < N; ++i)
	{
		int tmp = Arr[i];    //摸一张牌
		int j = i;
		for (j = i; j>0 && Arr[j - 1] > tmp; --j)
			Arr[j] = Arr[j - 1];  //移出空位
		Arr[j] = tmp;    //新牌落位
	}
}

void swap(ElementType *p, ElementType *q)
{
	ElementType cnt = *p;
	*p = *q;
	*q = cnt;
}

int main6()
{
	ElementType A[] = { 2, 3, 6, 1, 3, 5, 6, 87, 3, 545, 21 };
	quick_sort(A, sizeof(A) / sizeof(A[0]));
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
		printf("%d ", A[i]);
	system("pause");
	return 0;
}