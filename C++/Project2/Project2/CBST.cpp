#include <math.h>
#include <stdlib.h>
#include <stdio.h>
//完全二叉搜索树
#define T_MAX  10
typedef int TNode;

//比较器
int compare(const void*a, const void*b)
{
	return *(int *)a - *(int *)b;
}

void sort(TNode Arr[], int N)
{
	for (int i = N - 1; i >= 0; --i)
	{
		int flag = 0;   //设置标志
		for (int j = 0; j < N - 1; ++j)  //一趟冒泡
		{
			if (Arr[j] > Arr[j + 1])
			{
				int tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;
				flag = 1;   // 发生了交换，将标志置位
			}
		}
		if (flag == 0)
			break;
	}
}

//计算左子树的规模
int getLeftLength(int N)
{
	int H = (int)(log((double)N + 1) / log((double)2));
	
	int X = N - (int)pow((double)2,H) + 1;
	X = X < (int)pow((double)2, (H - 1)) ? X : (int)pow((double)2, (H - 1));
	return (int)pow((double)2, (H - 1)) - 1 + X;
}

//生成一颗完全二叉搜索树
void creatCBST(int ALeft,   //二叉树在左边的端点
	       int ARight,  //二叉树在右边的端点
		   int TRoot,   //要写入的完全二叉搜索树的根节点的位置
		   TNode A[],   //存放数据的数组
		   TNode T[]    //生成的完全二叉树的存放数组
		   )
{
	//初始的时候，solvw(0,N-1,0)

	//递归出口
	int n = ARight - ALeft + 1;
	if (n == 0)
		return;
    //计算n个节点的树的左子树有多少个节点
	int L = getLeftLength(n);
	T[TRoot] = A[ALeft + L];

	//递归的调用
	int RootLeft = TRoot * 2 + 1;
	int RootRight = RootLeft + 1;
	creatCBST(ALeft, ALeft + L - 1, RootLeft,A,T);   //左递归
	creatCBST(ALeft + L + 1, ARight, RootRight,A,T); //右递归
}

void printCBST(TNode A[],int N)
{
	//按照层序遍历输出
	for (int i = 0; i < N; ++i)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

/*****************测试程序****************************/
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