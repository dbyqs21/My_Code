#include <stdlib.h>
#include <stdio.h>
typedef int TNode;
#define T_MAX  10

//根据先序遍历和中序遍历放入结果来输出后续遍历的结果（不需要建树）
void PosteriorTraversal(TNode Pre[],   //先序遍历的数组
						TNode Mid[],   //中序遍历的数组
						TNode Pos[],   //后续遍历的数组
						int preL,      //先序遍历的起始下标
						int midL,      //中序遍历的起始下标
						int posL,      //后序遍历的起始下标
						int N          //数组规模
						)
{
	if (N == 0) return;
	if (N == 1) 
	{
		Pos[posL] = Pre[preL];
		return;
	}
	int k = 0;
	for (; k < N; ++k)   //根据前序遍历的第一个节点在中序遍历中找根对应的位置
	{
		if (Mid[midL + k] == Pre[preL])
		{
			break;
		}
	}
	Pos[posL+N-1] = Pre[preL];
	PosteriorTraversal(Pre, Mid, Pos, preL + 1, midL, posL, k);   //左递归
	PosteriorTraversal(Pre, Mid, Pos, preL + k + 1, midL+k+1, posL+k, N-k-1);    //右递归
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

