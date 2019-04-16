#include <iostream>

using namespace std;
class Job{
public :
    int key,job,index;
};
void Sort(Job b[],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
    {
        if(b[j].key>b[j+1].key)
        {
            Job temp=b[j];
            b[j]=b[j+1];
            b[j+1]=temp;
        }
    }
}
int FlowShop(int n,int a[],int b[],int c[])
{
    Job d[n];
    for(int i=0;i<n;i++)
    {
        d[i].key=a[i]>b[i]?b[i]:a[i];
        d[i].index=i;
        d[i].job=(a[i]<=b[i]);
    }

    Sort(d,n);
    int j=0,k=n-1;
    for(int i=0;i<n;i++)
    {
        if(d[i].job)
            c[j++]=d[i].index;
        else
            c[k--]=d[i].index;
    }
    j=a[c[0]];
    k=j+b[c[0]];
    for(int i=1;i<n;i++)
    {
        j+=a[c[i]];
        k=j<k?k+b[c[i]]:j+b[c[i]];
        cout<<k<<"   ";
    }
    return k;
}

int main()
{
    int n;
    cout<<"input n:";
    cin>>n;
    int a[n],b[n],c[n];
    cout<<"input a[i]:"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"input b[i]:"<<endl;
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<FlowShop(n,a,b,c)<<endl;
    for(int i=0;i<n;i++)
        cout<<c[i]<<"----";
    return 0;
}
