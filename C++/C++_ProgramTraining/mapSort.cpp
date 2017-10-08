#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/**< 定义一个小于比较类，来判断T类型的大小 */
template<class T>
struct LESS : binary_function<T,T,bool>
{
    bool operator()(const T & x, const T & y)
    {
        // return x<y;  // 按照字典顺序排序
        return x.length()<y.length();  // 按照字符串的长度排序
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

// 定义自己的比较器类，可以实现更改map在排序的时候的排序指标

void mapSortBykey()
{
    map<string,int,LESS<string>> m;
    m["yueyong"]=1;
    m["lipeng"]=2;
    m.insert(map<string,int,LESS<string>>::value_type("gousheng",3));


    // 输出map中的元素
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}

// 根据pair的第二个字段来排序
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
