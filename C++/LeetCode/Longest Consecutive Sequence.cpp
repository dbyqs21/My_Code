#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int> const& num)
{
    unordered_map<int, bool> m;

    for (auto i:num)
        m[i]=false;

    int longest=0;

    for (auto i : num)
    {
        if (m[i]) continue;

        int length=1;
        m[i] = true;
        for (int j=i+1; m.find(j) != m.end(); ++j)
        {
            m[j] = true;
            ++length;
        }

        for (int j=i-1; m.find(j) != m.end(); --j)
        {
            m[j]=true;
            ++length;
        }
        longest=max<int>(longest, length);
    }
    return longest;
}

