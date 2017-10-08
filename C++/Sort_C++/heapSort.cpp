#include <iostream>
#include <algorithm>
using namespace std;

/**< 堆排序，需要创建一个堆，堆的元素是放在数组中的，从下标为1的元素开始存放。 */

template <class T>
class MaxHeap
{
public:
    MaxHeap(int N):size(0),capacity(N)
    {
        heap = new T[capacity+1];
    }

    MaxHeap():size(0),capacity(31)
    {
        heap = new T[capacity+1];
    }

    // 向堆中插入元素
    void insert(T key)
    {
        if (size == capacity)  //若堆满
        {
            // 开始扩展堆
            capacity=capacity*2+1;
            T * newHeap = new T[capacity+1];
            for (int i=0; i<size; ++i)
            {
                newHeap[i]=heap[i];
            }
            delete [] heap;
            heap=newHeap;
        }
        // 开始向堆中插入元素
        int index=size+1;
        for (; index > 1 && heap[index/2]<key; index/=2)
        {
            heap[index]=heap[index/2];
        }
        heap[index]=key;
        size++;
    }

    void create(T arr[], int N)
    {
        if (N > capacity)
        {
            capacity=N+1;
            delete [] heap;
            heap = new T[capacity+1];
        }

        for (int i=0; i<N; i++)
        {
            heap[i+1] = arr[i];
        }
        size=N;

        // 开始将刚才放入的数据调整为一个堆
        for (int parent=N/2,child=parent*2; parent>0 ; parent--) //从最后一个元素的父节点开始，将其调整为一个最大堆
        {
            if(child != N && heap[child+1] > heap[child])
            {
                child++;
            }

            if (heap[parent] < heap[child])
            {
                swap(heap[parent], heap[child]);
            }
        }
    }

    T pop()
    {
        if (size < 1)
        {
            cout<<"最大堆已空"<<endl;
            return;
        }

        heap[0]=heap[1];  // heap[0]中存放将要删除的元素
        T tmp = heap[size--]; // 将堆的最后一个元素移到根的位置

        // 开始调整堆，使得它满足最大堆的条件
        int parent;
        int child;
        for (parent=1; parent*2 <=size; parent = child)
        {
            child=parent*2;   //先假设左儿子大

            /**< 将child指向左右儿子中最大的那个 */
            if( child !=size && heap[child+1] > heap[child])  //右儿子比左儿子大
            {
                child++;
            }

            if( tmp > heap[child]) //如果tmp比左右儿子中最大的那个还要大，则直接跳出循环，parent位置就是tmp应该放的地方
            {
                break;
            }
            else
            {
                heap[parent] = heap[child];  //将左右二子中较大的那个向上移
            }
        }
        heap[parent] = tmp;
        return heap[0];
    }

    void printMaxHeap()
    {
        int i=1;
        while(i<=size)
        {
            for (int j=1; j<=pow(2,(log(i)/log(2)-1))+1; ++i)
            {
                cout<<heap[i]<<" ";
            }
            cout<<endl;
        }
    }


private:
    T * heap;
    int size;
    int capacity;
};
