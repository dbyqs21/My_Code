#include <math.h>
#include <stdlib.h>
#include <stdio.h>
//��ȫ����������
#define T_MAX  10
typedef int TNode;

//�Ƚ���
int compare(const void*a, const void*b)
{
	return *(int *)a - *(int *)b;
}

void sort(TNode Arr[], int N)
{
	for (int i = N - 1; i >= 0; --i)
	{
		int flag = 0;   //���ñ�־
		for (int j = 0; j < N - 1; ++j)  //һ��ð��
		{
			if (Arr[j] > Arr[j + 1])
			{
				int tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;
				flag = 1;   // �����˽���������־��λ
			}
		}
		if (flag == 0)
			break;
	}
}

//�����������Ĺ�ģ
int getLeftLength(int N)
{
	int H = (int)(log((double)N + 1) / log((double)2));
	
	int X = N - (int)pow((double)2,H) + 1;
	X = X < (int)pow((double)2, (H - 1)) ? X : (int)pow((double)2, (H - 1));
	return (int)pow((double)2, (H - 1)) - 1 + X;
}

//����һ����ȫ����������
void creatCBST(int ALeft,   //����������ߵĶ˵�
	       int ARight,  //���������ұߵĶ˵�
		   int TRoot,   //Ҫд�����ȫ�����������ĸ��ڵ��λ��
		   TNode A[],   //������ݵ�����
		   TNode T[]    //���ɵ���ȫ�������Ĵ������
		   )
{
	//��ʼ��ʱ��solvw(0,N-1,0)

	//�ݹ����
	int n = ARight - ALeft + 1;
	if (n == 0)
		return;
    //����n���ڵ�������������ж��ٸ��ڵ�
	int L = getLeftLength(n);
	T[TRoot] = A[ALeft + L];

	//�ݹ�ĵ���
	int RootLeft = TRoot * 2 + 1;
	int RootRight = RootLeft + 1;
	creatCBST(ALeft, ALeft + L - 1, RootLeft,A,T);   //��ݹ�
	creatCBST(ALeft + L + 1, ARight, RootRight,A,T); //�ҵݹ�
}

void printCBST(TNode A[],int N)
{
	//���ղ���������
	for (int i = 0; i < N; ++i)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

/*****************���Գ���****************************/
int main2()
{
	TNode A[T_MAX] = { 2, 3, 1, 4, 5, 6, 7, 8, 9, 0 };
	TNode T[T_MAX];
	//qsort(A, 10, sizeof(TNode), compare);
	sort(A, 10);
	creatCBST(0, 9, 0, A, T);
	printCBST(T, 10);
    
	system("pause");
	return 0;
}