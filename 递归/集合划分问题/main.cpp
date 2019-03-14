#include <iostream>

using namespace std;
int divide(int n,int m){
    if(m==1||n==m)
        return 1;
    return divide(n-1,m-1)+m*divide(n-1,m);
}
int main()
{
    int n,count=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        count+=divide(n,i);
    cout <<count<< endl;
    return 0;
}
