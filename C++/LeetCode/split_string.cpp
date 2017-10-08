#include <vector>
#include <iostream>
#include <string>
using namespace std;
/**
    * @param s: A string
    * @return: A list of lists of string
    */
vector<vector<string>> partition_string(string s)
{
    // write your code here
    vector<vector<string>> str;
    string ss;
    int flag=1;
    int j=0;
    for (int i=0; i<s.size(); i++)
    {
        flag=1;
        for (j=i; j<s.size(); ++j)
        {
            ss.push_back(s[i]);

            // 判断ss中的子串是不是回文
            for (int i=0,j=ss.size()-1; i<j; ++i,--j)
            {
                if (ss[i] != ss[j])
                {
                    flag=0;
                    ss.erase(ss.end());
                    vector<string> cnt;
                    cnt.push_back(ss);
                    str.push_back(cnt);
                }
            }
        }
        i=j;
        ss.clear();
    }
    return str;
}

void print(vector<vector<string>> A)
{
    for (auto i : A)
    {
        for (auto j : i)
        {
            cout<<j<<endl;
        }
    }
}

void test1()
{

}
