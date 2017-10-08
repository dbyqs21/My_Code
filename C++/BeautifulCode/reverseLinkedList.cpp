// C++ source code
#include <iostream>
#include <stdlib.h>
#include <cstddef>

#define nullptr 0

using namespace std;

/** \brief 只遍历没有头节点的单向链表一次，将链表中的元素反转
 *
 * \param
 * \param
 * \return
 *
 */

 typedef struct node{
    int data;
    node * next;
}Node;

 Node * reverseLinkedList(Node * pHead)
 {
    Node * p=pHead;
    Node *pNext;
    Node *pLast=nullptr;
    //更改next指针使其指向上一个节点
    while(p->next!=nullptr)
    {
        pNext=p->next;
        p->next=pLast;
        pLast=p;
        p=pNext;
    }
    p->next=pLast;
    return p;
 }

void reverseLinkedList_test()
{

    Node *n1,*n2,*n3,*n4;
    n1=new Node();
    n2=new Node();
    n3=new Node();
    n4=new Node();
    n1->data=5;
    n1->next=n2;
    n2->data=6;
    n2->next=n3;
    n3->data=7;
    n3->next=n4;
    n4->data=8;
    n4->next=NULL;
    Node *head=reverseLinkedList(n1);
    while(head!=nullptr)
    {

        cout<<"node value is "<<head->data<<endl;
        head=head->next;
    }
}
