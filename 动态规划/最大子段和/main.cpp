#include <iostream>

using namespace std;
int a[10];
int Start;
int End;
int MaxSub(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int thisSum=0;
        for(int j=i;j<=n;j++)
        {
            thisSum+=a[j];
            if(thisSum>sum)
            {
                Start=i;
                End=j;
                sum=thisSum;
            }
        }
    }
    return sum;
}
int MaxSub1(int n)
{
    int b=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        if(b>0)
            b+=a[i];
        else
        {
           b=a[i];
           Start=i;
        }
        if(sum<b)
        {
            sum=b;
            End=i;
        }
    }
    return sum;
}
int main()
{
    int n;
    cout<<"input n:";
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    //cout<<MaxSub(n);
    cout<<MaxSub1(n);
    cout<<"   "<<Start<<"   "<<End<<endl;
    return 0;
}
