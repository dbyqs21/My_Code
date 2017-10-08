// C++ source code
#include <iostream>
#include <algorithm>
#inclide <unordered_set>
using namespace std;

/** \brief 找出一个链表的环的起始节点
 *
 * \param
 * \param
 * \return
 *
 */

 struct Node
 {
     int value;
     Node * pNext;
 };

 Node *  isCyclicLinkedList_hash(Node * pHead)
 {
     if (pHead != nullptr)
     {
         Node * p=pHead;
        unordered_set<int> hashtable;
        if (hashtable.find(p) != hashtable.end())
        {
            return p;
        }
        else
        {
            hashtable.insert(p);
            p=p->pNext;
        }
     }
     else
     {
         return pHead;
     }
 }


 Node *  isCyclicLinkedList(Node * pHead)
 {
     if (pHead != nullptr)
     {
         Node * pStart=pHead;
         while (pStart !=nullptr) // 如果没到链表结尾
         {
             Node * p=pStart->pNext;
             while (null != p)
             {
                 if (p!=pStart)
                 {
                    p=p->pNext;
                 }
                else
                {
                    return p;
                }
             }
             pStart=pStart->pNext;
         }
         return nullptr;
     }
     else
     {
        return pHead;
     }
 }
