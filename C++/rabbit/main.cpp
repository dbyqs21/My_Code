#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int x=0;
    int y=0;
    cout<<"���������ӵ�������ʱ��(��λΪ��):"<<endl;
    cin>>x>>y;
    if (x < 3 || y <3)
    {
        cout<<"��������ӵ�������ʱ��Ӧ�ô���3"<<endl;
        return 0;
    }
    vector<pair<int, int> > rabbit;
    rabbit.push_back(make_pair(2,0));
    int number=1;  //��¼���ӵ���������λ����

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
        cout<<y<<"��󣬵��ϵ����ӵ������ܺ���"<<nSumAge<<endl;

    return 0;
}
