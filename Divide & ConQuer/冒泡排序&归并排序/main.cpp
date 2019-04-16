#include <iostream>
#include<ctime>
#include<fstream>
#include<stdlib.h>
using namespace std;
template<class Type>
int read(Type A[])
{
    int i=0;
    Type a;
    ifstream if1("E:\\dataset\\more\\data_50000");
    while(!if1.eof())
    {
        if1>>a;
        A[i++]=a;
        if1.get();
        if(if1.peek()=='\n')
            break;

    }
    if1.close();
    return i;
}
template<class Type>
void write(Type a[],Type b[],int n)
{
    int i;
    ofstream out("E:\\MergeData.txt");
    if(out)
    {
        for(i=0;i<n;i++)
        {
            out<<a[i]<<endl;
        }
        out.close();
    }
    ofstream out1("E:\\BubbleData.txt");
    if(out1)
    {
        for(i=0;i<n;i++)
        {
            out1<<b[i]<<endl;
        }
        out1.close();
    }
}

template<class Type>
void BubbleSort(Type a[],int n)
{
    Type temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
template<class Type>
void Merge(Type a[],int left,int mid,int right)
{
    Type temp[right-left+1];
    int i=left;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=right)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=right)
        temp[k++]=a[j++];
    for(int p=0;p<k;p++)
        a[p+left]=temp[p];
}
template<class Type>
void MergeSort(Type a[],int left,int right)
{
    if(left<right)
    {
        int i=(left+right)/2;
        MergeSort(a,left,i);
        MergeSort(a,i+1,right);
        Merge(a,left,i,right);
    }
}
int main()
{
    int a[50001];
    int b[50001];
    int n=read(a);
    int n1=read(b);
    clock_t BubbleStartTime,BubbleEndTime,MergeStartTime,MergeEndTime;
    int MergeFlag=1,BubbleFlag=1;
    MergeStartTime =clock();
    MergeSort(a,0,n-1);
    MergeEndTime=clock();
     BubbleStartTime =clock();
    BubbleSort(b,n1);
    BubbleEndTime=clock();
    write(a,b,n);
    for(int i=0;i<n-1;i++)
        if(a[i]>a[i+1])
        {
            MergeFlag=0;
            break;
        }
    if(MergeFlag)
    {
         cout<<"MergeSort success"<<endl;
         cout<<endl<<n<<"  data  MergeSort time"<<MergeEndTime-MergeStartTime;
    }
    else
        cout<<"MergeSort fail"<<endl;
    for(int i=0;i<n1-1;i++)
        if(b[i]>b[i+1])
        {
            BubbleFlag=0;
            break;
        }
    if(BubbleFlag)
    {

        cout<<endl<<"BubbleSort success"<<endl;
        cout<<endl<<n<<"  data  BubbleSort time"<<BubbleEndTime-BubbleStartTime;
    }
    else
        cout<<"BubbleSort fail"<<endl;
    return 0;
}
