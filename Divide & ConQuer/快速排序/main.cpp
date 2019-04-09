#include <iostream>

using namespace std;
template<class Type>
int Partition1(Type a[],Type p,Type r)
{
    a[0]=a[p];
    while(p<r){
        while(p<r&&a[r]>a[0])
            r--;
        if(p<r){
            a[p]=a[r];
            p++;
        }
        while(p<r&&a[p]<a[0])
            p--;
        if(p<r){
            a[r]=a[p];
            r--;
        }
    }
    a[p]=a[0];
    return p;
}
template<class Type>
void Swap(Type &a,Type &b)
{
    Type temp=a;
    a=b;
    b=temp;
}
template<class Type>
int Partition(Type a[],int p,int r)
{
    if(p<r)
    {
        int temp=a[r];
        int i=p-1;
        for(int j=p;j<=r-1;j++)
        {
            if(a[j]<temp){
                i++;
                Swap(a[i],a[j]);
            }
        }
        Swap(a[i+1],a[r]);
        return i+1;
    }
}
template<class Type>
void QuickSort(Type a[],int p,int r)
{
    if(p<r)
    {
        int q=Partition(a,p,r);
        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }
}
template<class Type>
void QuickSort1(Type a[],int p,int r)
{
    if(p<r)
    {
        int q=Partition1(a,p,r);
        QuickSort1(a,p,q-1);
        QuickSort1(a,q+1,r);
    }
}
int main()
{
    int a[]={0,1,5,2,7,4,8,6,9,3};
    int len=sizeof(a)/sizeof(a[0]);
    QuickSort(a,1,len-1);
    for(int i=1;i<len;i++)
        cout<<a[i]<<"   ";
        cout<<endl;
    int b[]={0,1,5,2,7,4,8,6,9,3};
    int len1=sizeof(b)/sizeof(b[0]);
    QuickSort(b,1,len-1);
    for(int i=1;i<len;i++)
        cout<<b[i]<<"   ";
    return 0;
}
