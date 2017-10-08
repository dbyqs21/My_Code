//C++ source code

#include <iostream>
#include <climits>

using namespace std;

/** \brief ��ջʵ��һ�����У��ܹ���������ֲ�������ӣ������Լ��������Ԫ��
 *
 * \param
 * \param
 * \return
 *
 */
template<class T>
 class CStack
 {
 public:
    stack()
    {
        stackTop=-1;
        maxStackItemIndex=-1;
    }

    void push(T x)
    {
        stackTop++;
        if (stackTop >= MAXN)
        {
            cout<<"ջ�е�Ԫ����������ջ������"<<endl;
            return;
        }
        else
        {
            stackItem[stackTop]=x;
            if (x> max())
            {
                link2NextMaxItem(stackTop)= maxStackItemIndex;
                maxStackItemIndex=stackTop;
            }
            else
            {
                link2NextMaxItem[stackTop] =-1;
            }
        }

    }

    T pop()
    {
        T ret;
        if (stackTop < 0)
        {
            ThrowException();
        }
        else
        {
            ret=stackItem[stackTop];
            if(stackTop == maxStackItemIndex)
            {
                maxStackItemIndex = link2NextMaxItem[stackTop];
            }
            stackTop--;
        }
        return ret;
    }

    T max()
    {
        if (maxStackItemIndex >= 0)
            return stackItem[maxStackItemIndex];
        else
            return -INF;
    }

 private:
     const int MAXN=20;
    T stackItem[MAXN];
    int stackTop;
    int link2NextMaxItem[MAXN];
    int maxStackItemIndex;
 };

