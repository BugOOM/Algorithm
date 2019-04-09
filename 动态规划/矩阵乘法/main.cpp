#include <iostream>

using namespace std;
int m[10][10];
int p[10];
int s[10][10];
void init(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        m[i][j]=0;
        s[i][j]=0;
    }
}
void LoopMartix(int n)
{
    for(int r=2;r<=n;r++)
        for(int i=1;i<=n-r+1;i++)
    {
        int j=i+r-1;
        m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
        s[i][j]=i;
        for(int k=i+1;k<j;k++)
        {
            int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
            if(m[i][j]>t)
            {
                m[i][j]=t;
                s[i][j]=k;
            }
        }
    }
}
int RecurSionMatrix(int i,int j)
{
    if(m[i][j]>0)
        return m[i][j];
    if(i==j)
        return 0;
    int Min=RecurSionMatrix(i,i)+RecurSionMatrix(i+1,j)+p[i-1]*p[i]*p[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++)
    {
        int t=RecurSionMatrix(i,k)+RecurSionMatrix(k+1,j)+p[i-1]*p[k]*p[j];
        if(t<Min)
        {
            Min=t;
            s[i][j]=k;
        }
    }
    m[i][j]=Min;
    return Min;
}
void show(int i,int j)
{
    if(i==j)
        cout<<i;
    else
    {
        cout<<"(";
        show(i,s[i][j]);
        show(s[i][j]+1,j);
        cout<<")";
    }
}
void showM(int n)
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<m[i][j]<<"        ";
        cout<<endl;
    }
}
void showS(int n)
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<s[i][j]<<"        ";
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    init(n);
    for(int i=0;i<=n;i++)
        cin>>p[i];
    //LoopMartix(n);
    cout<<RecurSionMatrix(1,n)<<endl;
    showM(n);
    cout<<endl;
    showS(n);
    cout<<endl;
    show(1,n);
    return 0;
}
