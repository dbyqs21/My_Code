#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
void merge1(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd);
void divRecursion(ElementType A[], ElementType TmpA[], int L, int RightEnd);
void mergePass(ElementType A[], ElementType TmpA[], int N, int Length);

//���εݹ��㷨��ͳһ�ӿ�
void divRecursion_sort(ElementType A[], int N)
{
	int Length = 1; // ��������еĳ���
	ElementType * TmpA = (ElementType *)malloc(N*sizeof(ElementType));
	if (TmpA !=NULL)
	{
		while (Length < N)
		{
			mergePass(A, TmpA, N, Length);
			Length *= 2;
			mergePass(TmpA, A, N, Length);
			Length *= 2;
		}
		free(TmpA);
	}
	else
	{
		printf("�ڴ�ռ䲻��");
	}
}

////���εݹ��㷨  �ȶ� O(NlogN)
//void divRecursion(ElementType A[], ElementType TmpA[], int L, int RightEnd)
//{
//	int center;
//	if (L < RightEnd)
//	{
//		center = (L + RightEnd) / 2;
//		divRecursion(A, TmpA, L, center);
//		divRecursion(A, TmpA, center + 1, RightEnd);
//		merge(A, TmpA, L, center + 1, RightEnd);
//	}
//}

void merge1(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{

	int LeftEnd = R - 1;  //����������е��յ�����ұ����еĿ�ʼλ��
	int Tmp = L; // ��Ž������������λ��
	int NumberElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}

	while (L <= LeftEnd)   //ֱ�Ӹ����������ʣ�µ�����
		TmpA[Tmp++] = A[L++];
	while (R <= RightEnd)   //ֱ�Ӹ����ұ�����ʣ�µ�����
		TmpA[Tmp++] = A[R++];
	
	////�����ݴ��ԭ����
	//for (int k = 0; k < NumberElements; ++k, RightEnd--)
	//	A[RightEnd] = TmpA[RightEnd];
}

//�鲢����ǵݹ��㷨
void mergePass(ElementType A[], ElementType TmpA[], int N, int Length) //Length Ϊ���������еĳ���
{
	int k = 0;
	for (k = 0; k <= N - 2 * Length; k += 2 * Length)
		merge1(A, TmpA, k, k + Length, k + 2 * Length - 1);
	if (k + Length < N)
		merge1(A, TmpA, k, k + Length, N - 1);
	else
	for (int i = k; i < N; ++i)
		TmpA[i] = A[i];
}


/******************���Դ���*******************************/
void main5()
{
	ElementType A[11] = { 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
	divRecursion_sort(A,11);
	for (int k = 0; k < 11; k++)
	{
		printf("%d ", A[k]);
	}
	printf("\n");
	system("pause");
}