#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct HeapStruct *MaxHeap;
typedef  int  ElementType;

struct HeapStruct{
	ElementType *Elements;  //存储堆元素的数字
	int size;    //对当前元素的个数
	int capacity;   //堆的最大存储容量
};

bool isFull(MaxHeap H)
{
	return (H->size) == (H->capacity) ? true : false;
}

bool isEmpty(MaxHeap H)
{
	return H->size == 0 ? true : false;
}

//初始化一个最大可以存放MaxSize个元素的数组来存放堆
MaxHeap creat(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType *)malloc((MaxSize + 1)*sizeof(ElementType));  //堆的元素是从数组的1下标对应的元素开始的。
	H->size = 0;
	H->capacity = MaxSize;
	H->Elements[0] = 0;
	return H;
}

//向最大堆中插入一个元素
void insert(MaxHeap H, ElementType item)
{
	int i;
	if (isFull(H))
	{
		printf("最大堆已满！");
		return;
	}
	i = ++(H->size); // i指向插入堆中的最后一个元素
	for (; H->Elements[i / 2]<item; i /= 2)
	{
		H->Elements[i] = H->Elements[i / 2];   //向下过滤节点
	}
	H->Elements[i] = item;   //将item插入堆中
}

//从最大堆中取出键值最大的元素并且删除一个节点
ElementType deleatMax(MaxHeap H)
{
	int Parent, Child;
	ElementType MaxItem, temp;
	if (isEmpty(H))
	{
		printf("最大堆已空");
		return -1;
	}
	MaxItem = H->Elements[1];    //取出根节点的最大值
	// 用最大堆中的最后一个元素从根节点开始向上过滤下层节点
	temp = H->Elements[(H->size)--];
	for (Parent = 1; Parent * 2 < H->size; Parent = Child)
	{
		Child = Parent * 2; //假定左儿子大
		if (Child != H->size && H->Elements[Child] < H->Elements[Child + 1])
			Child++;   //Child指向左右儿子中较大的那个
		if (temp >= H->Elements[Child])
			break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MaxItem;
}

//利用传入数组中的元素来初始化一个大顶堆
void createMaxHeap(MaxHeap H, ElementType Arr[], int N)
{
	if (H->capacity < N)
	{
		printf("所给元素的个数超过了堆的最大存储容量！");
		return;
	}
	for (int k = 0; k<N; ++k)
		H->Elements[1+(H->size++)] = Arr[k];
	//将存储的元素调整为一个大顶堆
	for (int k = H->size / 2; k>0; --k)
	{
		//k所在的节点的左右子树一定是个大顶堆，需要将头结点加入这个大顶堆中
		int LChild = k * 2;
		for (; LChild <= H->size; LChild *= 2) //向下遍历
		{
			ElementType tmp = H->Elements[LChild / 2];   //保存头结点的值，以便交换
			if (LChild <H->size && H->Elements[LChild] < H->Elements[LChild + 1]) //有右儿子 并且左儿子的值比右儿子小
				LChild++;
			//LChild指向左右两个孩子中较大的那个
			if (tmp<H->Elements[LChild])
			{
				//交换父节点和大孩子的值
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
