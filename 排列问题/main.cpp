#include <iostream>

using namespace std;
template<class Type>
inline void Swap(Type &a,Type &b){
    Type temp=a;
    a=b;
    b=temp;
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
        Swap(List[k],List[i]);
        Perm(List,k+1,m);
        Swap(List[k],List[i]);
    }
}

int main()
{
    char c[10]={' ','a','b','c'};
    Perm(c,1,3);
    return 0;
}
