#include<iostream>
using namespace std;
#define N 20
int c[N][N];
int b[N][N];
char x[N];
char y[N];
void LCSLength(int m,int n)
{
    int i,j;
    for(i=1;i<=m;i++)
        c[i][0]=0;
    for(j=1;j<=n;j++)
        c[0][j]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
    {
        if(x[i]==y[j])
        {
            c[i][j]=c[i-1][j-1]+1;
            b[i][j]=1;
        }
        else if(c[i-1][j]>=c[i][j-1])
        {
            b[i][j]=2;
            c[i][j]=c[i-1][j];
        }
        else
        {
            b[i][j]=3;
            c[i][j]=c[i][j-1];
        }
    }
}
void LCS(int m,int n)
{
    if(m==0||n==0)
        return;
    if(b[m][n]==1)
    {
        LCS(m-1,n-1);
        cout<<x[m];
    }
    else if(b[m][n]==2)
        LCS(m-1,n);
    else
        LCS(m,n-1);
}
int main()
{
    int m,n;
    cout<<"input m n";
    cin>>m>>n;
    cout<<"input x"<<endl;
    for(int i=1;i<=m;i++)
        cin>>x[i];
    cout<<"input y"<<endl;
    for(int i=1;i<=n;i++)
        cin>>y[i];
    LCSLength(m,n);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<c[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
    LCS(m,n);
    return 0;
}
