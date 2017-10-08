// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
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

//����һ������������һ������ʵ�ֵĶ�����
void creatBinTreebyArr(CNode *& root, int Arr[], int N, int& index)
{
	/*
	dataΪ�洢�ڵ����ݵ����飬nΪdata����ĳ��ȣ�indexΪ�����������indexҲҪ������
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
		creatBinTreebyArr(root->pLeft, Arr, N, index);  //�ݹ鹹��������  
		creatBinTreebyArr(root->pRight, Arr, N, index);  //�ݹ鹹��������  
	}
}


//���������������
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

//���������������
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

//���������������
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


//������������Ķ��ֲ���
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

//ѡ������:���ȶ���ʱ�临�Ӷ�ΪO(n^2)���ȶ���nСʱ�Ϻá�
void selection_sort(int Arr[], int N)
{
	for (int i = 0; i < N; ++i)   //ѡ������
	{
		int minPosition=i;
		for (int j = i; j < N; ++j)
		{
			if (Arr[minPosition]>Arr[j])
				minPosition = j;
		}
		//�����ҳ�����СԪ�غ͵�ǰλ�ý���
		int tmp = Arr[i];
		Arr[i] = Arr[minPosition];
		Arr[minPosition] = tmp;
	}
}

//ϣ������:���ȶ���ʱ�临�Ӷ�ΪO(nlogn)�����ܺ�������ѡ���й�
void Shell_sort(int Arr[], int N)
{
	for (int D = N / 2; D > 0; D /= 2)  //������ʽ   Hibbard����D(k)=2^k-1;Sedgewick����D(k)=9*4^k-9*2^k+1 ��D(k)=4^k-3*2^k+1
	{
		//�������򣬼��ΪD
		for (int i = D; i<N; ++i)
		{
			int tmp = Arr[i];    //��һ����
			int j = i;
			for (j = i; j >= D && Arr[j - D] > tmp; j -= D)
				Arr[j] = Arr[j - D];  //�Ƴ���λ
			Arr[j] = tmp;    //������λ
		}
	}
} 

//��������:�ȶ���ʱ�临�Ӷ�ΪO(n^2)���ȶ���nСʱ�Ϻá���������˳��T=O(N);����������T=O(N^2)����ƽ��ʱ�临�Ӷ�����Ϊn^2
void insertion_sort(int Arr[], int N)
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

//ð������:�ȶ���ʱ�临�Ӷ�ΪO(n^2)���ȶ���nСʱ�Ϻá���������˳��T=O(N);����������T=O(N^2)����ƽ��ʱ�临�Ӷ�����Ϊn^2
void Bubble_sort(int Arr[], int N)
{
	for (int i = N-1; i >= 0 ; --i)
	{
		int flag = 0;   //���ñ�־
		for (int j = 0; j < N-1; ++j)  //һ��ð��
		{
			if (Arr[j] > Arr[j+1])
			{
				int tmp = Arr[j];
				Arr[j] = Arr[j+1];
				Arr[j+1] = tmp;
				flag = 1;   // �����˽���������־��λ
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




	////����������
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


