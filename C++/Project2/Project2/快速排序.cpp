#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void swap(ElementType *p, ElementType *q);
void insertion_sort(int Arr[], int N);
ElementType Median3(ElementType A[], int Left, int Right);
void quickSort(ElementType A[], int Left, int Right);

//��������
void quick_sort(ElementType A[], int N)
{
	quickSort(A, 0, N-1);
}

void quickSort(ElementType A[], int Left, int Right)
{
	int cutoff = 4;
	if (cutoff <= Right - Left)  //���������Ĺ�ģ���ڵ�������
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
		swap(&A[i], &A[Right - 1]);  //����Ԫ�����м��λ��
		quickSort(A, Left, i - 1);
		quickSort(A, i+1, Right);
    }
	else
		insertion_sort(A + Left, Right - Left + 1);  //���С��ģ���⣬���ò�������
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
	swap(&A[middle], &A[Right - 1]);   //����Ԫ�������ұ�Ԫ�ص�ǰһ��
	return A[Right - 1];
}


//��������:�ȶ���ʱ�临�Ӷ�ΪO(n^2)���ȶ���nСʱ�Ϻá���������˳��T=O(N);����������T=O(N^2)����ƽ��ʱ�临�Ӷ�����Ϊn^2
void insertion_sort(ElementType Arr[], int N)
{
	for (int i = 1; i < N; ++i)
	{
		int tmp = Arr[i];    //��һ����
		int j = i;
		for (j = i; j>0 && Arr[j - 1] > tmp; --j)
			Arr[j] = Arr[j - 1];  //�Ƴ���λ
		Arr[j] = tmp;    //������λ
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