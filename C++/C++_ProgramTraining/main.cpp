#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void mapSortBykey();
void mapSortByValue();


int main()
{
    mapSortBykey();
    mapSortByValue();
    return 0;
}
////void test2();
//void test4();
    //test4();

//    map<string,int> ss;
//    vector<string> v;
//    string s1;
//    while (cin>>s1)
//    {
//        ++ss[s1];
//    }
//    cout<<ss.size()<<endl;

//    map<string, int> words;
//    words.insert(pair<string, int>("Andy",1));
//    words.insert(pair<string, int>("YUE",1));
//    words.insert(pair<string, int>("Andy",7));
//    cout<<words.size()<<endl;
//    cout<<"��ֵΪAndy��Ԫ��ĳ��ִ���Ϊ��"<<words.count("Andy")<<endl;
//
//    map<string, int>::iterator it = words.begin();
//    while(it != words.end())
//    {
//        cout<<it->first<<" "<<it->second<<" ";
//        it++;
//    }
