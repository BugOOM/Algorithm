#include <iostream>

using namespace std;
template<class Type>
int MaxLoading(Type w[],Type c,int n)
{
    int i=0;
    int x[n+1],bestx[n+1];
    int bestw=0,cw=0,r=0;
    for(int j=0;j<n;j++)
        r+=w[j];
    while(1)
    {
        while(i<n&&cw+w[i]<=c)
        {
            x[i]=1;
            r-=w[i];
            cw+=w[i];
            i++;
        }
        if(i>n-1)
        {
            for(int j=0;j<n;j++)
                bestx[j]=x[j];
            //if(cw>bestw)
            bestw=cw;
        }else{
            r-=w[i];
            x[i]=0;
            i++;
        }
        while(cw+r<=bestw)
        {
            i--;
            while(i>-1&&!x[i]){
                r+=w[i];
                i--;
            }
            //cout<<i<<endl;
            if(i==-1)
            {
                for(int j=0;j<n;j++)
                    cout<<bestx[j]<<"   ";
                cout<<endl;
                return bestw;
            }
            x[i]=0;
            cw-=w[i];
            i++;
        }
    }
}
int main()
{
    int w[]={7, 4, 6, 1, 3};
    int c=15;
    int n=5;
    cout<<MaxLoading(w,c,n);
    return 0;

}
