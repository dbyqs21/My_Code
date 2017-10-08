#include<cstdio>
#include <iostream>
#include <vector>
using namespace std;
int Kolakoski()
{
    int n,m;
    cin>>n>>m;

    vector<int> a;
    int * arr=new int[m];
    for (int i=0;i<m;++i)
    {
        cin>>arr[i];
    }

    int count=0;
    int cnt=0;
    int j=0;
    int i=0;
    for(i=0;i<arr[0];++i)
    {
        a.push_back(arr[0]);
        cnt++;
    }
    count++;
    i=1;
    while(cnt < n)
    {
        for (j=0;j<a[i];++j)
        {
            a.push_back(arr[count]);
            cnt++;
        }
        count++;
        count%=m;
        i++;
    }

    int ll=0;
    for (auto i:a)
    {
        ll++;
        cout<<i<<' ';
    }
    cout<<endl<<ll<<endl;
    delete[] arr;
    return 0;
}
