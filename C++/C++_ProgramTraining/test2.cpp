#include <iostream>
using namespace std;

void test2()
{
    int a,b,n;
    cin>>a>>b>>n;
    int big=a>b?a:b;
    int small=a<b?a:b;
    int cnt=big;
    while (true)
    {
        if (small*(cnt/small) ==cnt)
        {
            break;
        }
        cnt+=big;
    }

    cout<<n/cnt<<endl;

}
