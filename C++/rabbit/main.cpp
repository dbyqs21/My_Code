#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int x=0;
    int y=0;
    cout<<"请输入兔子的寿命和时间(单位为年):"<<endl;
    cin>>x>>y;
    if (x < 3 || y <3)
    {
        cout<<"输入的兔子的寿命和时间应该大于3"<<endl;
        return 0;
    }
    vector<pair<int, int> > rabbit;
    rabbit.push_back(make_pair(2,0));
    int number=1;  //记录兔子的数量，单位：对

    for (int k=1;k<=y;k++)
    {
        for (int i=0;i<rabbit.size();++i)
        {
            rabbit[i].second++;
        }

        int cnt=rabbit.size();
        for (int i=0;i<cnt;++i)
        {
            if (k%2 == 0)
                rabbit.push_back(make_pair(2,0));
        }

        for (int i=0;i<rabbit.size();++i)
        {
            if (rabbit[i].second > x)
            {
                rabbit.erase(rabbit.begin()+i);
            }
        }

        if (rabbit.size() > 10)
        {
            rabbit.erase(rabbit.begin());
            rabbit.erase(rabbit.begin());
        }
    }

    int nSumAge=0;
    for (int i=0;i<rabbit.size();++i)
        {
            nSumAge += rabbit[i].second*rabbit[i].first;
        }
        cout<<y<<"年后，岛上的兔子的岁数总和是"<<nSumAge<<endl;

    return 0;
}
