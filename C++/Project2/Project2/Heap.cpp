#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct HeapStruct *MaxHeap;
typedef  int  ElementType;

struct HeapStruct{
	ElementType *Elements;  //�洢��Ԫ�ص�����
	int size;    //�Ե�ǰԪ�صĸ���
	int capacity;   //�ѵ����洢����
};

bool isFull(MaxHeap H)
{
	return (H->size) == (H->capacity) ? true : false;
}

bool isEmpty(MaxHeap H)
{
	return H->size == 0 ? true : false;
}

//��ʼ��һ�������Դ��MaxSize��Ԫ�ص���������Ŷ�
MaxHeap creat(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType *)malloc((MaxSize + 1)*sizeof(ElementType));  //�ѵ�Ԫ���Ǵ������1�±��Ӧ��Ԫ�ؿ�ʼ�ġ�
	H->size = 0;
	H->capacity = MaxSize;
	H->Elements[0] = 0;
	return H;
}

//�������в���һ��Ԫ��
void insert(MaxHeap H, ElementType item)
{
	int i;
	if (isFull(H))
	{
		printf("����������");
		return;
	}
	i = ++(H->size); // iָ�������е����һ��Ԫ��
	for (; H->Elements[i / 2]<item; i /= 2)
	{
		H->Elements[i] = H->Elements[i / 2];   //���¹��˽ڵ�
	}
	H->Elements[i] = item;   //��item�������
}

//��������ȡ����ֵ����Ԫ�ز���ɾ��һ���ڵ�
ElementType deleatMax(MaxHeap H)
{
	int Parent, Child;
	ElementType MaxItem, temp;
	if (isEmpty(H))
	{
		printf("�����ѿ�");
		return -1;
	}
	MaxItem = H->Elements[1];    //ȡ�����ڵ�����ֵ
	// �������е����һ��Ԫ�شӸ��ڵ㿪ʼ���Ϲ����²�ڵ�
	temp = H->Elements[(H->size)--];
	for (Parent = 1; Parent * 2 < H->size; Parent = Child)
	{
		Child = Parent * 2; //�ٶ�����Ӵ�
		if (Child != H->size && H->Elements[Child] < H->Elements[Child + 1])
			Child++;   //Childָ�����Ҷ����нϴ���Ǹ�
		if (temp >= H->Elements[Child])
			break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MaxItem;
}

//���ô��������е�Ԫ������ʼ��һ���󶥶�
void createMaxHeap(MaxHeap H, ElementType Arr[], int N)
{
	if (H->capacity < N)
	{
		printf("����Ԫ�صĸ��������˶ѵ����洢������");
		return;
	}
	for (int k = 0; k<N; ++k)
		H->Elements[1+(H->size++)] = Arr[k];
	//���洢��Ԫ�ص���Ϊһ���󶥶�
	for (int k = H->size / 2; k>0; --k)
	{
		//k���ڵĽڵ����������һ���Ǹ��󶥶ѣ���Ҫ��ͷ����������󶥶���
		int LChild = k * 2;
		for (; LChild <= H->size; LChild *= 2) //���±���
		{
			ElementType tmp = H->Elements[LChild / 2];   //����ͷ����ֵ���Ա㽻��
			if (LChild <H->size && H->Elements[LChild] < H->Elements[LChild + 1]) //���Ҷ��� ��������ӵ�ֵ���Ҷ���С
				LChild++;
			//LChildָ���������������нϴ���Ǹ�
			if (tmp<H->Elements[LChild])
			{
				//�������ڵ�ʹ��ӵ�ֵ
				H->Elements[LChild / 2] = H->Elements[LChild];
				H->Elements[LChild] = tmp;
			}
		}
	}
}

void printHeap(MaxHeap H)
{
	for (int i = 1; i<=H->size; ++i)
		printf("%d", H->Elements[i]);
	printf("\n");
}
int main1()
{
	ElementType Arr[] = { 1, 2, 3, 5, 6,7};
	MaxHeap H = creat(12);

	createMaxHeap(H, Arr,6);
	printHeap(H);

	insert(H, 4);
	printHeap(H);

	deleatMax(H);
	printHeap(H);

	printf("Hello world!\n");
	system("pause");
	return 0;
}
