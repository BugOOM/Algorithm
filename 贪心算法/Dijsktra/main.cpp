#include <iostream>

using namespace std;
#define Maxint 9999
#define Num 30

template<class Type>
void init(int n,int e,Type c[][Num])
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i][j]=Maxint;
    int v,u,w;
    cout<<"两点之间权值"<<endl;
    for(int i=1;i<=e;i++)
    {
        cin>>v>>u>>w;
        c[v][u]=w;
    }


//1 2 10
//2 3 50
//3 5 10
//4 5 60
//1 5 100
//4 3 20
//1 4 30
}
template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][Num])
{
    int s[n+1];
    for(int i=1;i<=n;i++)
    {
        dist[i]=c[v][i];
        s[i]=0;
        if(dist[i]==Maxint)
            prev[i]=0;
        else
            prev[i]=v;
    }
    s[v]=1;
    dist[v]=0;
    for(int i=1;i<n;i++)
    {
        int temp=Maxint;
        int u=v;
        for(int j=1;j<=n;j++)
        {
            if((!s[j])&&(dist[j]<temp))
            {
                u=j;
                temp=dist[j];
            }
        }
        s[u]=1;
        for(int j=1;j<=n;j++)
        {
            if((!s[j])&&(c[u][j]<Maxint))
            {
                Type ddd=dist[u]+c[u][j];
                if(ddd<dist[j])
                {
                    dist[j]=ddd;
                    prev[j]=u;
                }
            }
        }
    }
}
int main()
{
    int pointNum,edgeNum;
    int dist[Num],c[Num][Num],prev[Num];
    cout<<"输入顶点个数和边的数目";
    cin>>pointNum>>edgeNum;
    init(pointNum,edgeNum,c);
    Dijkstra(pointNum,1,dist,prev,c);
    for(int i=1;i<=pointNum;i++)
        cout<<dist[i]<<"  ";
    for(int i=1;i<=pointNum;i++)
    {
        int pre=prev[i];
        cout<<dist[i]<<"---"<<i;
        while(pre!=0)
        {
            cout<<"<-"<<pre;
            pre=prev[pre];
        }
        cout<<endl;
    }
    return 0;
}
