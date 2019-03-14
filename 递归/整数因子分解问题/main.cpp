#include <iostream>
using namespace std;
int Count=0;
int divide(int n)
{

    if(n==1||n==2)
        return 1;
    for(int i=3;i<=n;i++)
    {
        if(n%i==0)
           Count+= divide(n/i);
    }
    return Count;
}
int main()
{
    cout<<divide(12);

    return 0;
}
