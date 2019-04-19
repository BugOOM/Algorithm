#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<fstream>
#include<time.h>
#define N 10001
using namespace std;

class Point
{
public:
    double x,y;
    Point(double x1,double y1)
    {
        x=x1;
        y=y1;
    }
    Point()
    {

    }
};
Point p1,p2;
int read(Point a[])
{
    int i=0;
    double x,y;
    ifstream if1("E:\\dataset1\\more\\data_7000");
    while(!if1.eof())
    {
        if1>>x>>y;
        Point p(x,y);
        a[i++]=p;
//        if1.get();
//        if(if1.peek()=='\n')
//            break;
    }
    if1.close();
    return i;
}

void Swap(Point a,Point b)
{
    Point temp=a;
    a=b;
    b=temp;
}
//flag为1表示对x排序
int Partition(Point a[],int p,int r,int flag)
{
    Point temp=a[p];
    while(p<r)
    {
        if(flag)
            while(p<r&&a[r].x>temp.x)
                r--;
        else
            while(p<r&&a[r].y>temp.y)
                r--;
        if(p<r)
        {
            a[p]=a[r];
            p++;
        }
        if(flag)
            while(p<r&&a[p].x<temp.x)
                p++;
        else
            while(p<r&&a[p].y<temp.y)
                p++;
        if(p<r)
        {
            a[r]=a[p];
            r--;
        }
    }
    a[p]=temp;
    return p;
}
int RandomPartition(Point a[],int p,int r,int flag)
{
    int i=rand()%(r-p+1)+p;
    Swap(a[i],a[p]);
    return Partition(a,p,r,flag);
}

void QuickSort(Point a[],int p,int r,int flag)
{
    if(p<r)
    {
        int i=RandomPartition(a,p,r,flag);
        QuickSort(a,p,i-1,flag);
        QuickSort(a,i+1,r,flag);
    }
}

double Distance(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double closet(Point S[],int low,int high,int n)
{
    double d1,d2,d3,d;
    int mid,i,j,index=0;
    Point P[n];
    if(high-low==1)
    {
        p1=S[low];
        p2=S[high];
        return  Distance(S[low],S[high]);
    }
    if(high-low==2)
    {
        d1=Distance(S[low],S[low+1]);
        d2=Distance(S[low+1],S[high]);
        d3=Distance(S[low],S[high]);
        if((d1<d2)&&(d1<d3))
        {
            p1=S[low];
            p2=S[low+1];
            return d1;
        }
        else if(d2<d3)
        {
            p1=S[low+1];
            p2=S[high];
            return d2;
        }
        else
        {
            p1=S[low];
            p2=S[high];
            return d3;
        }

    }
    mid=(low+high)/2;
    d1=closet(S,low,mid,n);
    d2=closet(S,mid+1,high,n);
    if(d1<=d2)
        if(d<=d1)
            d=d1;
    else
        if(d<=d2)
            d=d2;
    for(i=mid;(i>=low)&&(S[mid].x-S[i].x<d);i--)
        P[index++]=S[i];
    for(i=mid+1;(i<=high)&&(S[i].x-S[mid].x<d);i++)
        P[index++]=S[i];

    QuickSort(P,0,index-1,0);

    for(i=0;i<index;i++)
    {
        for(j=i+1;j<index;j++)
        {
            if(P[j].y-P[i].y>=d)
                break;
            else
            {
                d3=Distance(P[i],P[j]);
                if(d3<d)
                {
                    d=d3;
                    p1=P[i];
                    p2=P[j];
                }
            }
        }
    }
    return d;
}
int main()
{
    Point p[N];
    int n=read(p)-1;
    QuickSort(p,0,n-1,1);
    clock_t start=clock();
    cout<<closet(p,0,n-1,n)<<endl;
    clock_t end=clock();
    cout<<end-start<<endl;
    cout<<p1.x<<"--"<<p1.y<<endl;
    cout<<p2.x<<"--"<<p2.y;
    return 0;
}


