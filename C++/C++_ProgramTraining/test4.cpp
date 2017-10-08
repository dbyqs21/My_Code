#include <iostream>
#include <vector>
using namespace std;

void test4()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(10);

    for(auto a: v)
    {
        cout<<a<<" ";
    }
    cout<<endl;

    v.erase(v.begin());

     for(auto a: v)
    {
        cout<<a<<" ";
    }
}
