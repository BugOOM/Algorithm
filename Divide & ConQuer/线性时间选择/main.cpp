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
    if(p<r)
    {
        Type temp=A[r];
        int i=p-1;
        for(int j=p;j<r;j++)
        {
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
int RandomPartition(Type A[],int p,int r)
{
    int i=rand()%(r-p+1)+p;
    Swap(A[i],A[p]);
    return Partition(A,p,r);
}
template<class Type>
Type RandomSelect(Type A[],int p,int r,int k)
{
    if(p==r)
        return A[p];
    int i=RandomPartition(A,p,r);
    int j=i-p+1;
    if(k<=j)
        return RandomSelect(A,p,i,k);
    else
        return RandomSelect(A,i+1,r,k-j);
}
int main()
{
    int a[]={1,3,5,7,8,9};
    int i=RandomSelect<int>(a,0,6,2);
    cout<<i;
    return 0;
}
