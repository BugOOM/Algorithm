#include <iostream>

using namespace std;
float e[10][10];
float w[10][10];
int s[10][10];
float p[10];
float q[10];
void OBST(int n)
{
    for(int i=0;i<=n;i++)
    {
        e[i+1][i]=q[i];
        w[i+1][i]=q[i];
    }
    for(int r=0;r<=n;r++)
        for(int i=1;i<=n+1-r;i++)
    {
        int j=i+r;
        w[i][j]=w[i][j-1]+p[j]+q[j];
        e[i][j]=e[i][i-1]+e[i+1][j]+w[i][j];
        s[i][j]=i;
        for(int k=i+1;k<=j;k++)
        {
            float temp=e[i][k-1]+e[k+1][j]+w[i][j];
            if(temp<e[i][j])
            {
                e[i][j]=temp;
                s[i][j]=k;
            }
        }
    }
}
void showE(int n)
{
    for(int i=1;i<=6;i++)
    {
        for(int j=0;j<=5;j++)
            cout<<e[i][j]<<"        ";
        cout<<endl;
    }
}
void showS(int n)
{
    for(int i=1;i<=6;i++)
    {
        for(int j=0;j<=5;j++)
            cout<<s[i][j]<<"    ";
        cout<<endl;
    }
}
void Printf(int i,int j)
{
    if(i==j+1)
        cout<<"(d"<<j<<")";
    else
    {
        cout<<"(";
        Printf(i,s[i][j]-1);
        cout<<"k"<<s[i][j];
        Printf(s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    int n;
    cout<<"input n:";
    cin>>n;
    cout<<"input p"<<endl;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    cout<<"input q"<<endl;
    for(int i=0;i<=n;i++)
        cin>>q[i];
    OBST(n);
    //showE(n);
    //showS(n);
    Printf(1,5);
    return 0;
}
