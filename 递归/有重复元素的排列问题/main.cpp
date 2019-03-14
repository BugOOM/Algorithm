#include <iostream>

using namespace std;
template<class Type>
inline void Swap(Type &a,Type &b){
    Type temp=a;
    a=b;
    b=temp;
}
template<class Type>
int change(Type List[],int m,int n)
{
    for(int i=m;i<n;i++){
        if(List[i]==List[n])
            return 0;
    }
    return 1;
}
template<class Type>
void Perm(Type List[],int k,int m){
    if(k==m){
        for(int i=0;i<=m;i++)
            cout<<List[i];
        cout<<endl;
    }
    else
    for(int i=k;i<=m;i++){
            if(change(List,k,i)){
        Swap(List[k],List[i]);
        Perm(List,k+1,m);
        Swap(List[k],List[i]);
            }
    }
}

int main()
{
    char c[10]={' ','a','b','c','b'};
    Perm(c,1,4);
    return 0;
}
