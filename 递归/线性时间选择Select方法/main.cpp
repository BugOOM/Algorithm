#include <iostream>

using namespace std;
template<class Type>
void Swap(Type &a,Type &b)
{
    Type temp=a;
    a=b;
    b=temp;
}
template<class Type>
int Partition(Type a[],Type p,Type r)
{
    Type temp=a[p];
    while(p<r){
        while(p<r&&a[r]>temp)
            r--;
        if(p<r){
            a[p]=a[r];
            p++;
        }
        while(p<r&&a[p]<temp)
            p++;
        if(p<r){
            a[r]=a[p];
            r--;
        }
    }
    a[p]=temp;
    return p;
}

template<class Type>
void quickSort(Type A[],int p,int r)
{
    if(p<r)
    {
        int i=Partition(A,p,r);
        quickSort(A,p,i-1);
        quickSort(A,i+1,r);
    }
}
template<class Type>
int Partition(Type A[],int p,int r,int k)
{
    int pos;
    for(int i=p;i<=r;i++)
    {
        if(A[i]==k){
            pos=i;
            break;
        }
    }
    Swap(A[pos],A[p]);
    int temp=A[p];
    while(p<r)
    {
        while(p<r&&A[r]>temp)
            r--;
        if(p<r)
        {
            A[p]=A[r];
            p++;
        }
        while(p<r&&A[p]<temp)
            p++;
        if(p<r)
        {
            A[r]=A[p];
            r--;
        }
    }
    A[p]=temp;
    return p;
}
template<class Type>
Type select(Type A[],int p,int r,int k)
{
    if(r-p<75)
    {
        quickSort(A,p,r);
        return A[p+k-1];
    }
    for(int i=0;i<=(r-p-4)/5;i++)
    {
        Type x=select(A,p,p+(r-p-4)/5,(r-p-4)/10);
        int i1=Partition(A,p,r,x);
        int j=r-p+1;
        if(k<=j)
            return select(A,p,i1,k);
        else
            return select(A,i1+1,r,k-j);
    }
}
int main()
{
    int a[]={3,6,1,5,7,9,2,4,
    13,16,11,15,17,19,12,14,
    23,26,21,25,27,29,22,24,
    33,36,31,35,37,39,32,34,
    43,46,41,45,47,49,42,44,
    53,56,51,55,57,59,52,54,
    63,66,61,65,67,69,62,64,
    73,76,71,75,77,79,72,74,
    83,86,81,85,87,89,82,84,
    93,96,91,95,97,99,92,94};
    int k=select(a,0,7,56);
    cout<<k;
    return 0;
}
