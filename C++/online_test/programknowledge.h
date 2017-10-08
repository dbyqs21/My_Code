#ifndef PROGRAMKNOWLEDGE_H_
#define PROGRAMKNOWLEDGE_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <vector>
using namespace std;


/******************************************************************************************/
/** \brief 通过求和的办法去找到数组中唯一的重复的元素
 *
 * \param int arr[] 存放整数的数组
 * \param int n数组的元素个数
 * \return void
 *
 */
void find_DouplicateNumber(int arr[], int n)
{
    int Xor_cnt1=1;
    int Xor_cnt2=arr[0];
    for (int i=2; i<n; i++)
    {
        Xor_cnt1^=i;
    }

    for (int i=1; i<n; ++i)
    {
        Xor_cnt2^=arr[i];
    }

    cout<<((Xor_cnt1^Xor_cnt2))<<endl;
}

/** \brief 通过求和的办法去找到数组中唯一的重复的元素
 *
 * \param int arr[] 存放整数的数组
 * \param int n数组的元素个数
 * \return void
 *
 */

void find_DouplicateNumber1(int arr[], int n)
{
    int sum1=0;
    int sum2=arr[0];
    for (int i=1; i<=n; i++)
    {
        sum1+=i;
    }

    for (int i=1; i<n; ++i)
    {
        sum2+=arr[i];
    }

    cout<<n-(sum1-sum2)<<endl;
}


/******************************************************************************************/

/** \brief 反转一个没有头结点的单链表
 *
 * \param
 * \param
 * \return
 *
 */

void reverseLinkedList()
{
    struct Node
    {
        int value;
        Node * next;

    public:
        Node(int i)
        {
            value=i;
            next=nullptr;
        }
    };

    Node * head = new Node(1);
    head->next=nullptr;
    Node * p = head;

    for (int i=2; i<7; i++)
    {
        p->next=new Node(i);
        p=p->next;

    }

    p=head;
    while(p!=nullptr)
    {
        cout<<p->value<<" ";
        p=p->next;
    }
    cout<<endl;

    // 反转没有头结点的链表
    Node * first = head;
    Node * current=first->next;

    while(first->next != nullptr)
    {
        current=first->next;
        first->next=current->next;
        current->next=head;
        head=current;
    }

    p=head;
    while(p!=nullptr)
    {
        cout<<p->value<<" ";
        p=p->next;
    }
    cout<<endl;
}

/******************************************************************************************/
void replaceBlank()
{
    char arr[]="we are happy ";
    vector<char> v;
    for (int i=0;i<strlen(arr);++i)
    {
        if(arr[i] ==' ')
        {
            v.push_back('%');
            v.push_back('2');
            v.push_back('0');
        }
        else
        {
            v.push_back(arr[i]);
        }
    }

    for (auto it=v.begin();it!=v.end();it++)
    {
        cout<<(*it);
    }
    cout<<endl;
}

/******************************************************************************************/

/*方法一：复杂度O(nlogn)*/
int count1(int n)
{
    int iCount = 0;
    while (n != 0)
    {
        iCount += (n % 10 == 1) ? 1 : 0;
        n /= 10;
    }//while

    return iCount;
}

int sum1s(int n)
{
    int iCount = 0;
    for (int i = 1; i <= n; ++i)
    {
        iCount += count1(i);
    }//for

    return iCount;
}

/*方法二：复杂度O(N的位数) 《编程之美》p134*/
int sum1s_2(int n)
{
    int iCount = 0;
    int iFactor = 1;

    int iLowerNum = 0, iCurrNum = 0, iHigherNum = 0;

    while (n / iFactor != 0)
    {
        iLowerNum = n - (n / iFactor) * iFactor;
        iCurrNum = (n / iFactor) % 10;
        iHigherNum = n / (iFactor * 10);

        switch (iCurrNum)
        {
        case 0:
            iCount += iHigherNum * iFactor;
            break;
        case 1:
            iCount += iHigherNum * iFactor + iLowerNum + 1;
            break;
        default:
            iCount += (iHigherNum + 1) * iFactor;
            break;
        }//switch

        iFactor *= 10;
    }//while
    return iCount;
}

/*方法三：复杂度O(logN*logN) 《程序员代码面试指南》 P429*/
int lenOfN(int n)
{
    int len = 0;
    while (n != 0)
    {
        ++len;
        n /= 10;
    }//while
    return len;
}

int powerBaseOf10(int base)
{
    return pow(10, base);
}

int sum1s_3(int n)
{
    if (n < 1)
    {
        return 0;
    }//if

    int len = lenOfN(n);
    if (1 == len)
    {
        return 1;
    }//if

    int tmp1 = powerBaseOf10(len - 1);
    int first = n / tmp1;
    int firstOneNum = first == 1 ? n % tmp1 + 1 : tmp1;
    int otherOneNum = first * (len - 1) * (tmp1 / 10);

    return firstOneNum + otherOneNum + sum1s_3(n % tmp1);
}

/******************************************************************************************/

#endif // PROGRAMKNOWLEDGE_H_

