#include <iostream>

using namespace std;
class Active{
public:
    int i,s,f;
};
void Sort(Active a[],int n)
{
    for(int i=1;i<n-1;i++)
        for(int j=1;j<n-i-1;j++)
    {
        if(a[j].f>a[j+1].f)
        {
            Active temp=a[j];
            a[j]=a[j+1];
            a[i+1]=temp;
        }
    }
}
void GreedySelector(int n,Active a[],int A[])
{
    Sort(a,n);
    A[1]=1;
    int j=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i].s>a[j].f)
        {
            A[i]=1;
            j=i;
        }
        else
            A[i]=0;
    }
}
int main()
{
    int n;
    cout << "input n:";
    cin>>n;
    n=n+1;
    Active a[n];
    int A[n];
    cout<<"input a[i]:"<<endl;
    for(int i=1;i<n;i++)
        cin>>a[i].i>>a[i].s>>a[i].f;
    GreedySelector(n,a,A);
    for(int i=1;i<n;i++)
        if(A[i]==1)
        cout<<a[i].i<<"---";
    return 0;
}
