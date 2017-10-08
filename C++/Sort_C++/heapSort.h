#ifndef HEAPSORT_H_
#define HEAPSORT_H_
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class MaxHeap   /**<  �����࣬�ѵ��±��1��ʼ���� */
{
private:
    T * data;
    int count;
    int capacity;

private:
    void shiftUp(int index)
    {
        while(index > 1 && data[index]>data[index/2])
        {
            swap(data[index], data[index/2]);
            index/=2;
        }
    }

    void shiftDown(int index)
    {
        while(index*2 <= count )
        {
            // �ҵ����Һ����������Ǹ�
            int j = index*2;   // jΪ����Ҫ�͸��ڵ㽻���ĺ���
            if (j+1<=count && data[j] < data[j+1])
            {
                j=j+1;
            }

            if (data[index] >= data[j]) // ������ڵ��ֵ�����������нϴ���Ǹ���Ҫ����ֱ���˳�ѭ��
            {
                break;
            }

            swap(data[index], data[j]);
            index=j;
        }
    }

public:
    MaxHeap(int capacity)
    {
        data = new T[capacity+1];
        count=0;
        this->capacity=capacity;
    }

    MaxHeap(T arr[], int n)
    {
        data=new T[n+1];
        capacity=n;
        count=n;
        for(int i=0; i < n; ++i)
        {
            data[i]=arr[i];
        }

        for (int i=n/2;i>=1;i--)  // ���������Ϊһ����
        {
            shiftDown(i);
        }
    }

    ~MaxHeap()
    {
        delete [] data;
    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void insert(T key)
    {

        if (count+1 > capacity)
        {
            capacity=capacity*2+1;
            T * pOldData = data;
            data = new T[capacity];
            for (int i = 1; i <= count; ++i)
            {
                data[i] = pOldData[i];
            }
            delete [] pOldData;
            pOldData=nullptr;

        }
        data[++count]=key;
        shiftUp(count);  // ����Ϊ����
    }

    T pop()
    {
        if (count >= 1)
        {
            data[0]=data[1];
            data[1] = data[count--];
            shiftDown(1);
            return data[0];
        }
        else
        {
            cout<<"�����ѿգ��޷�����"<<endl;
        }
    }
};

template<typename T>
void __shiftDown(T arr[], int n, int index)
{
    while (index*2+1 < n) /**< �����Ƿ���� */
    {
        int j=2*index+1;
        if (j+1 < n && arr[j+1] > arr[j]) /**< ���Һ��Ӵ��ڣ������Һ��Ӷ�ֵ�������ӵ�ֵ�� */
        {
            j+=1;  // j�б���ľ������Һ���ֵ�����Ǹ�
        }

        if (arr[index] >= arr[j]) // ��ǰ�ڵ��ֵ���������Һ������Ǹ�����
        {
            break;
        }

        swap(arr[index], arr[j]); // ��ǰ�ڵ��ֵ��С�����Һ������Ǹ�����
        index=j;
    }
}

template<typename T>
void heapsort(T arr[], int n) /**< �������µĴ洢�ռ䣬ԭ�ؽ�һ���������Ϊһ�����ѣ��Ѵ��±�Ϊ0��λ�ÿ�ʼ���� */
{

    // heapify
    for (int i=(n-1)/2;i>=0;--i)
    {
        __shiftDown(arr,n,i);
    }

    for (int i=n-1;i>0;--i)
    {
        swap(arr[i],arr[0]);
        __shiftDown(arr,i,0);
    }
}




template<typename T>
void heapsort1(T arr[], int n)
{
    MaxHeap<T> maxheap(arr,n);
//    for (int i =0; i < n ; ++i)
//    {
//        maxheap.insert(arr[i]);
//    }

    for (int i =n-1; i >=0 ; i--)
    {
        arr[i] = maxheap.pop();
        // cout<<arr[i]<<" ";
    }
}


template<typename T>
class IndexMaxHeap   /**<  �����࣬�ѵ��±��1��ʼ���� */
{
private:
    T * data;
    int * indexs;
    int count;
    int capacity;

private:
    void shiftUp(int index)
    {
        while(index > 1 && data[indexs[index]>data[indexs[index/2]])
        {
            swap(indexs[index], indexs[index/2]);
            index/=2;
        }
    }

    void shiftDown(int index)
    {
        while(index*2 <= count )
        {
            // �ҵ����Һ����������Ǹ�
            int j = index*2;   // jΪ����Ҫ�͸��ڵ㽻���ĺ���
            if (j+1<=count && data[indexs[j]] < data[indexs[j+1]])
            {
                j=j+1;
            }

            if (data[indexs[index]] >= data[indexs[j]]) // ������ڵ��ֵ�����������нϴ���Ǹ���Ҫ����ֱ���˳�ѭ��
            {
                break;
            }

            swap(indexs[index], indexs[j]);
            index=j;
        }
    }

public:
    IndexMaxHeap(int capacity)
    {
        data = new T[capacity+1];
        indexs=new int[capacity+1];
        count=0;
        this->capacity=capacity;
    }

    IndexMaxHeap(T arr[], int n)
    {
        data=new T[n+1];
        indexs=new int[capacity+1];
        capacity=n;
        count=n;
        for(int i=0; i < n; ++i)
        {
            data[i]=arr[i];
        }

        for (int i=n/2;i>=1;i--)  // ���������Ϊһ����
        {
            shiftDown(i);
        }
    }

    ~IndexMaxHeap()
    {
        delete [] data;
        delete [] indexs;
    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    // �����i���û���˵���Ǵ�0������
    void insert(int k, T key)
    {

        if (count+1 > capacity)
        {
            capacity=capacity*2+1;
            T * pOldData = data;
            int * pOldIndexs = indexs;
            data = new T[capacity];
            indexs = new int[capacity];

            for (int i = 1; i <= count; ++i)
            {
                data[i] = pOldData[i];
                indexs[i] = pOldIndexs[i];
            }
            delete [] pOldData;
            delete [] pOldIndexs;
            pOldData=nullptr;
            pOldIndexs=nullptr;

        }
        data[++count]=key;
        indexs[count]=count;
        shiftUp(count);  // ����Ϊ����
    }

    T pop()
    {
        if (count >= 1)
        {
            data[0]=data[indexs[1]];
            indexs[1] = indexs[count--];
            shiftDown(1);
            return data[0];
        }
        else
        {
            cout<<"�����ѿգ��޷�����"<<endl;
        }
    }


};

#endif // HEAPSORT_H_
