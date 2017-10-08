#include <stdlib.h>
#include <stdio.h>
typedef int TNode;
#define T_MAX  10

//����������������������������������������Ľ��������Ҫ������
void PosteriorTraversal(TNode Pre[],   //�������������
						TNode Mid[],   //�������������
						TNode Pos[],   //��������������
						int preL,      //�����������ʼ�±�
						int midL,      //�����������ʼ�±�
						int posL,      //�����������ʼ�±�
						int N          //�����ģ
						)
{
	if (N == 0) return;
	if (N == 1) 
	{
		Pos[posL] = Pre[preL];
		return;
	}
	int k = 0;
	for (; k < N; ++k)   //����ǰ������ĵ�һ���ڵ�������������Ҹ���Ӧ��λ��
	{
		if (Mid[midL + k] == Pre[preL])
		{
			break;
		}
	}
	Pos[posL+N-1] = Pre[preL];
	PosteriorTraversal(Pre, Mid, Pos, preL + 1, midL, posL, k);   //��ݹ�
	PosteriorTraversal(Pre, Mid, Pos, preL + k + 1, midL+k+1, posL+k, N-k-1);    //�ҵݹ�
	return;
}

void printBT(TNode Arr[], int N)
{
	for (int i = 0; i < N; ++i)
	{
		printf("%d ", Arr[i]);
	}
	printf("\n");

}

int main3()
{
	TNode Pre[T_MAX] = {1,2,3,4,5,6};
	TNode Mid[T_MAX] = {3,2,4,1,6,5};
	TNode Pos[T_MAX];

	PosteriorTraversal(Pre, Mid, Pos, 0, 0, 0, 6);
	printBT(Pos, 6);

	system("pause");
	return 0;
}

