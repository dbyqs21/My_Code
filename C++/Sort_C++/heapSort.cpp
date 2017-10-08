#include <iostream>
#include <algorithm>
using namespace std;

/**< ��������Ҫ����һ���ѣ��ѵ�Ԫ���Ƿ��������еģ����±�Ϊ1��Ԫ�ؿ�ʼ��š� */

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

    // ����в���Ԫ��
    void insert(T key)
    {
        if (size == capacity)  //������
        {
            // ��ʼ��չ��
            capacity=capacity*2+1;
            T * newHeap = new T[capacity+1];
            for (int i=0; i<size; ++i)
            {
                newHeap[i]=heap[i];
            }
            delete [] heap;
            heap=newHeap;
        }
        // ��ʼ����в���Ԫ��
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

        // ��ʼ���ղŷ�������ݵ���Ϊһ����
        for (int parent=N/2,child=parent*2; parent>0 ; parent--) //�����һ��Ԫ�صĸ��ڵ㿪ʼ���������Ϊһ������
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
            cout<<"�����ѿ�"<<endl;
            return;
        }

        heap[0]=heap[1];  // heap[0]�д�Ž�Ҫɾ����Ԫ��
        T tmp = heap[size--]; // ���ѵ����һ��Ԫ���Ƶ�����λ��

        // ��ʼ�����ѣ�ʹ�����������ѵ�����
        int parent;
        int child;
        for (parent=1; parent*2 <=size; parent = child)
        {
            child=parent*2;   //�ȼ�������Ӵ�

            /**< ��childָ�����Ҷ����������Ǹ� */
            if( child !=size && heap[child+1] > heap[child])  //�Ҷ��ӱ�����Ӵ�
            {
                child++;
            }

            if( tmp > heap[child]) //���tmp�����Ҷ����������Ǹ���Ҫ����ֱ������ѭ����parentλ�þ���tmpӦ�÷ŵĵط�
            {
                break;
            }
            else
            {
                heap[parent] = heap[child];  //�����Ҷ����нϴ���Ǹ�������
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
