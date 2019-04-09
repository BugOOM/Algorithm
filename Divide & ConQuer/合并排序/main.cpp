#include <iostream>

using namespace std;
template<class Type>
void Merge(Type a,int left,int mid,int right)
{
    int temp[right-left+1];
    int i=left;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=right)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }
    for(i=0;i<k;i++){
        a[left+i]=temp[i];
    }
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
    int a[]={8,1,5,2,7,3,9,6};
    int len=sizeof(a)/sizeof(a[0]);
    cout<<len<<endl;
    MergeSort(a,0,7);
    for(int i=0;i<len;i++){
        cout<<a[i]<<"  ";
    }
    return 0;
}
