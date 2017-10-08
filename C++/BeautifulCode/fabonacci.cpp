#include <iostream>
using namespace std;
int fibonacci(int N)
{
    if (N <=0)
    {
        //cout<<"the number you input is not a positive integer"<<endl;
        return 0;
    }

    if (N == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(N-1)+fibonacci(N-2);
    }
}
