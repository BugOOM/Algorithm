#include <iostream>
#include<stdlib.h>
#include<fstream>
#define N 10000
using namespace std;
template<class Type>

int Partition1(Type a[],Type p,Type r)
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
template<class Type>
void WriteFile(Type A[])
{
    int i;
    ofstream out("E:\\data.txt");
    if(out)
    {
        for(i=0;i<N;i++)
        {
            out<<A[i]<<endl;
        }
        out.close();
    }
}
template<class Type>
void ReadFile(Type A[])
{
    int i=0,a;
    ifstream if1("E:\\data.txt");
    while(!if1.eof())
    {
        if1>>a;
        A[i++]=a;
        if1.get();
        if(if1.peek()=='\n')
            break;
    }
    if1.close();
}
int main()
{
    int a[N],b[N];
    int flag=1;
    for(int i=0;i<N;i++)
    {
        a[i]=rand()%(N);
    }
    int len=sizeof(a)/sizeof(a[0]);
    QuickSort(a,0,len-1);
    WriteFile(a);
    ReadFile(b);
    for(int i=0;i<len-1;i++)
       if(b[i]>b[i+1])
       {
           cout<<"ÅÅÐòÊ§°Ü"<<endl;
            flag=0;
           break;
       }
        if(flag==1)
            cout<<"ÅÅÐò³É¹¦";
//    int b[]={11,1,5,2,7,4,8,6,9,3};
//    int len1=sizeof(b)/sizeof(b[0]);
//    QuickSort1(b,0,len-1);
//    for(int i=0;i<len;i++)
//        cout<<b[i]<<"   ";
    return 0;
}
