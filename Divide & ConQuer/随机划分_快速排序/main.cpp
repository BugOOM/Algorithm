#include <iostream>
#include<stdlib.h>
using namespace std;
template<class Type>
void Swap(Type &a,Type &b)
{
    Type temp=a;
    a=b;
    b=temp;
}
template<class Type>
int Partition(Type A[],int p,int r)
{
    if(p<r){
        Type temp=A[r];
        int i=p-1;
        for(int j=p;j<r;j++){
            if(A[j]<temp)
            {
                i++;
                Swap(A[j],A[i]);
            }
        }
        Swap(A[i+1],A[r]);
        return i+1;
    }
}
template<class Type>
int randomPartition(Type A[],int p,int r)
{
    int i=rand()%(r-p+1)+p;
    Swap(A[p],A[i]);
    return Partition(A,p,r);
}
template<class Type>
void RandomQuickSort(Type A[],int p,int r)
{
    if(p<r)
    {
        int q=randomPartition(A,p,r);
        RandomQuickSort(A,p,q-1);
        RandomQuickSort(A,q+1,r);
    }
}
int main()
{
    cout << "Hello world!" << endl;
    int a[]={4,1,3,7,8,5,2};
    int len=sizeof(a)/sizeof(a[0]);
    RandomQuickSort(a,0,len-1);
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<"   ";
    }
    return 0;
}
