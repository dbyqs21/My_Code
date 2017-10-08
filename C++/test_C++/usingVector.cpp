#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <functional> //greater<T>
using namespace std;

/**< ʹ��˳������ģ��vector */

template<class T>
void printVector(char *s, const vector<T>& V)
{
    cout<<*s<<"=(";
    if (V.size() == 0)
    {
        cout<<")"<<endl;
        return;
    }

    typename vector<T>::const_iterator i=V.begin();
    for (; i!=V.end(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<")"<<endl;
}

bool f1(int n)
{
    return n<4;
}

void usingVector()
{
    int a[]= {1,2,3,4,5};
    vector<int> v1;
    printVector("v1",v1);

    for (int j=1; j<=5; j++)
    {
        v1.push_back(j);
    }

    vector<int> v2(3,7);   // ����Ԫ�ص����������Ҷ�����ʼ��Ϊ7
    vector<int>::iterator i1=v1.begin()+1;
    vector<int> v3(i1,i1+2);    //v3(2,3)
    vector<int> v4(v1);
    vector<int> v5(5);

    v5[1]=v5.at(3)=9;

    v3.reserve(6);   //����v3���ڴ�ռ䣬Ҳ������洢����
    v4.resize(7); // v4=(1,2,3,4,5,0,0), size=7,capacity=10
    v4.resize(3);  // v4=(1,2,3), size=3,capacity=10;
    v4.clear();    //v4=(),size=0,capacity=10;

    v4.insert(v4.begin(),v1[1]);
    v4.insert(v4.end(),v3.at(1));
    v4.insert(v4.end(),2,4); // ��end֮�����2��4
    v4.insert(v4.end(),v1.begin()+1,v1.end()-1);

    // ����
    v4.erase(v4.end()-2);
    v4.erase(v4.end()-2,v4.end());

    // ɾ��ԭ������������������
    v4.assign(3,8);   // v4(8 8 8)
    v4.assign(a,a+3);   //v4(1,2,3)

    // ���������
    vector<int>::reverse_iterator ri3=v4.rbegin();
    for(; ri3!=v4.rend(); ++ri3)
    {
        cout<<*ri3<<" ";
    }
    cout<<endl;

    /**< �㷨��� */
    v5[0]=3;
    replace_if(v5.begin(), v5.end(), f1,7);
    printVector("v5",v5);
    v5[0]=3;
    v5[2]=v5[4]=0;
    replace(v5.begin(),v5.end(),0,9);   //��v5�е�0�滻Ϊ9
    printVector("v5",v5);
    sort(v5.begin(),v5.end());  //����������
    printVector("v5",v5);
    sort(v5.begin(),v5.end(),greater<int>());   //����������
    v5.front()=2;
}
