#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


//class MaxPoint
//{
//public:
//    MaxPoint()
//    {
//        cin>>size;
//        p=new vector<pair<int, int> >[size];
//        int x,y;
//        for (int i=0; i<size; ++i)
//        {
//            cin>>x>>y;
//            p[i].push_back(pair(x,y));
//        }
//    }
//
//    bool judgefrom_first(const pair<int,int> a, const pair<int,int> b)
//    {
//        return a.first>b.first;
//    }
//
//    bool judgefrom_second(const pair<int,int> a, const pair<int,int> b)
//    {
//        return a.second>b.second;
//    }
//
//    void printMaxPoint()
//    {
//        sort(p.begin(), p.end(), judgefrom_first);
//        vector<pair<int, int>> p2(p);
//
//        sort(p2.begin(), p2.end(), judgefrom_second);
//        while (true)
//        {
//            if (*(p.end()-1).first )
//        }
//
//    }
//
//
//
//private:
//    vector<pair<int, int>> p;
//    int size;
//};
int main()
{
//    MaxPoint maxpoint;
    //maxpoint.printMaxPoint();
    vector<int> a;
    a.push_back(3);
    cout<<*(a.end()-1);

    return 0;
}
