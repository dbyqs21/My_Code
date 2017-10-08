
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;



bool Compare(pair<int,long> & a,pair<int,long> & b)
{
    return a.first>b.first;
}

int test5_1()
{
    int n;
    cin>>n;
    int t;
    long c;
    map<int,long> m;
    vector<pair<int,long>> v;
    for (int i=0; i<n; i++)
    {
        cin>>t>>c;
        if (m.insert(make_pair(t,c)).second == false)
        {
            v.push_back(make_pair(t,c));
        }
    }

    if (v.size() == 0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        sort(v.begin(),v.end(),Compare);
        for (int i=0; i<v.size(); ++i)
        {
            cout<<v[i].first<<" "<<v[i].second<<" "<<m[v[i].first]<<endl;
        }
    }
    return 0;
}


int test5_2()
{
    int n;
    cin>>n;
    int t;
    long c;
    multimap<int,long> m;
    vector<pair<int,long>> v;
    for (int i=0; i<n; i++)
    {
        cin>>t>>c;
        m.insert(make_pair(t,c));
    }

    multimap<int,long>::iterator it;
    it=m.begin();
    while (it != m.end())
    {
        auto i = m.equal_range((*it).first);

        if(i.first != m.end())
        {

           for (auto j=i.first; j != i.second; ++j)
           {
               cout<<(*j).first<<" "<<(*j).second<<endl;
           }
        }
        it=i.second;
    }


    return 0;
}


