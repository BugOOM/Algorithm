#include <iostream>
#include<stdlib.h>
using namespace std;
template<class Type>
class Loading{
public:
    int n;
    Type *w,c,cw,bestw,r,*bestx,*x;
    void backTrack(int i);
};
template<class Type>
void Loading<Type>::backTrack(int i)
{
    if(i>n-1)
    {
        //cout<<cw<<"---";
        if(cw>bestw)
        {
            for(int j=0;j<n;j++)
                bestx[j]=x[j];
            bestw=cw;
        }
           // cout<<bestw<<endl;
        return ;
    }
    r-=w[i];
    if(cw+w[i]<=c)
    {
        x[i]=1;
        cw+=w[i];
        backTrack(i+1);
        cw-=w[i];
    }
    if(cw+r>bestw)
    {
        x[i]=0;
        backTrack(i+1);
    }
    r+=w[i];
}
template<class Type>
Type MaxLoading(Type w[],Type c,int n)
{
    Loading<Type> X;
    X.x=new int[n+1];
    X.bestx=new int[n+1];
    X.w=w;
    X.c=c;
    X.n=n;
    X.bestw=0;
    X.cw=0;
    for(int i=0;i<n;i++)
        X.r+=w[i];
    X.backTrack(0);
    for(int i=0;i<n;i++)
        cout<<X.bestx[i]<<"    ";
    cout<<endl;
    return X.bestw;
}
int main()
{
    int w[]={7, 4, 6, 1, 3};
    int c=15;
    int n=5;
    cout<<MaxLoading(w,c,n);
    return 0;
}
