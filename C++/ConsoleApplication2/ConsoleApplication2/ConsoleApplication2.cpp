// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "CLinkSteak.h"
#include "CBST.h"
using namespace std;

class CNode {
public:
	int data;
	CNode * pLeft;
	CNode * pRight;

	CNode(int value) :data(value), pLeft(nullptr), pRight(nullptr){} 
};

//根据一个数组来产生一个链表实现的二叉树
void creatBinTreebyArr(CNode *& root, int Arr[], int N, int& index)
{
	/*
	data为存储节点数据的数组，n为data数组的长度，index为数组的索引。index也要用引用
	*/
	if (index >= N)
	{
		return;
	}
	int e = Arr[index++];
	if (e == '#'){
		root = nullptr;
	}
	else{
		root = new CNode(e);
		creatBinTreebyArr(root->pLeft, Arr, N, index);  //递归构建左子树  
		creatBinTreebyArr(root->pRight, Arr, N, index);  //递归构建右子树  
	}
}


//二叉树的先序遍历
void PreOrderTraversal(CNode *& BT)
{
	if (BT)
	{
		cout << BT->data << " ";
		PreOrderTraversal(BT->pLeft);
		PreOrderTraversal(BT->pRight);
	}
	cout << endl;
}

//二叉树的中序遍历
void InOrderTraversal(CNode *& BT)
{
	if (BT)
	{
		InOrderTraversal(BT->pLeft);
		cout << BT->data << " ";
		InOrderTraversal(BT->pRight);
	}
	cout << endl;
}

//二叉树的中序遍历
void PostOrderTraversal(CNode *& BT)
{
	if (BT)
	{
		PostOrderTraversal(BT->pLeft);
		PostOrderTraversal(BT->pRight);
		cout << BT->data << " ";
	}
	cout << endl;
}


//基于有序数组的二分查找
int BinarySearch(int Arr[], int N, int value)
{
	int left, right, mid, NoFound = -1;
	left = 0;
	right = N;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (value > Arr[mid])
		{
			left = mid;
		}
		else if (value < Arr[mid])
		{
			right = mid;
		}
		else
			return mid;
	}
	return NoFound;
}

//选择排序:不稳定，时间复杂读为O(n^2)，稳定，n小时较好。
void selection_sort(int Arr[], int N)
{
	for (int i = 0; i < N; ++i)   //选择趟数
	{
		int minPosition=i;
		for (int j = i; j < N; ++j)
		{
			if (Arr[minPosition]>Arr[j])
				minPosition = j;
		}
		//交换找出的最小元素和当前位置交换
		int tmp = Arr[i];
		Arr[i] = Arr[minPosition];
		Arr[minPosition] = tmp;
	}
}

//希尔排序:不稳定，时间复杂读为O(nlogn)。性能和增量的选择有关
void Shell_sort(int Arr[], int N)
{
	for (int D = N / 2; D > 0; D /= 2)  //增量方式   Hibbard增量D(k)=2^k-1;Sedgewick增量D(k)=9*4^k-9*2^k+1 或D(k)=4^k-3*2^k+1
	{
		//插入排序，间隔为D
		for (int i = D; i<N; ++i)
		{
			int tmp = Arr[i];    //摸一张牌
			int j = i;
			for (j = i; j >= D && Arr[j - D] > tmp; j -= D)
				Arr[j] = Arr[j - D];  //移出空位
			Arr[j] = tmp;    //新牌落位
		}
	}
} 

//插入排序:稳定，时间复杂读为O(n^2)，稳定，n小时较好。最好情况：顺序T=O(N);最坏情况：逆序T=O(N^2)；其平均时间复杂度下限为n^2
void insertion_sort(int Arr[], int N)
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

//冒泡排序:稳定，时间复杂读为O(n^2)，稳定，n小时较好。最好情况：顺序T=O(N);最坏情况：逆序T=O(N^2)；其平均时间复杂度下限为n^2
void Bubble_sort(int Arr[], int N)
{
	for (int i = N-1; i >= 0 ; --i)
	{
		int flag = 0;   //设置标志
		for (int j = 0; j < N-1; ++j)  //一趟冒泡
		{
			if (Arr[j] > Arr[j+1])
			{
				int tmp = Arr[j];
				Arr[j] = Arr[j+1];
				Arr[j+1] = tmp;
				flag = 1;   // 发生了交换，将标志置位
			}
		}
		if (flag == 0)
			break;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int Arr[] = { 4, 2, 5, 1, 6, 9, 5 ,16};
	Shell_sort(Arr, sizeof(Arr) / sizeof(Arr[0]));
	for (auto K : Arr)
		cout << K << " ";
	cout << endl;




	////创建二叉树
	//CNode * root = nullptr;
	//int N = sizeof(Arr) / sizeof(Arr[0]);
	//for (int k = 0; k < N; ++k)
	//{
	//	creatBinTreebyArr(root, Arr, N, k);
	//}

	//PreOrderTraversal(root);

	system("pause");
	return 0;
}


