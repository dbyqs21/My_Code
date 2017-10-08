#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int fibonacci(int N);
int maxDifference(int num[], int N);
int maxSum(int arr[], int N);
int maxSum1(int arr[], int N);
int LIS(int arr[],int N);
void arrayRightShift(int arr[], int N, int K);
void arrayLeftShift(int arr[], int N, int K);
void printWords();
int calculateStringDistance(string strA, int pABegin, int pAEnd,
                             string strB, int pBBegin, int pBEnd);
void reverseLinkedList_test();
void reBuild_test();
int main()
{
    cout<<fibonacci(10)<<endl;

    int num[]={1,2,3,1,3,-8,2,9,-1,0,18,17};
    int N=sizeof(num)/sizeof(num[0]);
    cout<<maxDifference(num,sizeof(num)/sizeof(num[0]))<<endl;

    cout<<maxSum1(num,sizeof(num)/sizeof(num[0]))<<endl;
    cout<<LIS(num,sizeof(num)/sizeof(num[0]))<<endl;
    arrayRightShift(num,sizeof(num)/sizeof(num[0]),2);
    for (int k=0;k<N;++k)
    {
        cout<<num[k]<<" ";
    }
    cout<<endl;

//    cout<<"找出电话号码对应的单词"<<endl;
//    printWords();

    string strA="abcdefg";
    string strB="abcdef";
    cout<<calculateStringDistance(strA,1,7,strB,1,6)<<endl;

    reverseLinkedList_test();
    void reBuild_test();
    cout << "Hello world!" << endl;
    system("pause");
    return 0;
}
