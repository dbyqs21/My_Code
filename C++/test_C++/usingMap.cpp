#include <iostream>
#include <map>

using namespace std;

void test5()
{
    map<string, int> myMap;
    myMap["Andy"] = "YUE"    //由于myMap 中以前没有Andy这个关键字，所以该语句会插入一个关键字Andy到map中，并且将该关键字的值设为YUE

}
