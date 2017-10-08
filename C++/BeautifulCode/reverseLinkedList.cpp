// C++ source code
#include <iostream>
#include <stdlib.h>
#include <cstddef>

#define nullptr 0

using namespace std;

/** \brief ֻ����û��ͷ�ڵ�ĵ�������һ�Σ��������е�Ԫ�ط�ת
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
    //����nextָ��ʹ��ָ����һ���ڵ�
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
