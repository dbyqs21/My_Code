#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/**< ����һ��С�ڱȽ��࣬���ж�T���͵Ĵ�С */
template<class T>
struct LESS : binary_function<T,T,bool>
{
    bool operator()(const T & x, const T & y)
    {
        // return x<y;  // �����ֵ�˳������
        return x.length()<y.length();  // �����ַ����ĳ�������
    }
};

template<class T>
struct GREATER : binary_function<T,T,bool>
{
    bool operator()(const T & x, const T & y)
    {
        return x>y;
    }
};

// �����Լ��ıȽ����࣬����ʵ�ָ���map�������ʱ�������ָ��

void mapSortBykey()
{
    map<string,int,LESS<string>> m;
    m["yueyong"]=1;
    m["lipeng"]=2;
    m.insert(map<string,int,LESS<string>>::value_type("gousheng",3));


    // ���map�е�Ԫ��
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}

// ����pair�ĵڶ����ֶ�������
template<typename T>
bool compare_by_value(const T & x, const T & y)
{
    return x.second<y.second;
}

template<typename T>
struct Compare_by_value
{
    bool operator()(const T & x, const T & y)
    {
        return x.second<y.second;
    }
};

void mapSortByValue()
{
    vector<pair<string,int>> v;
    v.push_back(make_pair("yueyong",1));
    v.push_back(make_pair("gousheng",3));
    v.push_back(make_pair("lipeng",2));
    //sort(v.begin(),v.end(),Compare_by_value<pair<string,int>>());
    sort(v.begin(),v.end(),compare_by_value<pair<string,int>>);

    for(auto it=v.begin();it!=v.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}
