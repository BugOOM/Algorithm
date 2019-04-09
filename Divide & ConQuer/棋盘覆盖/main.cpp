#include <iostream>

using namespace std;
int total=0;
int Board[100][100];
void ChessBoard(int tr,int tc,int dr,int dc,int Size)
{
    if(Size==1)
        return ;
    int t=total++;
    int s=Size/2;
    if(dr<tr+s&&dc<tc+s)
        ChessBoard(tr,tc,dr,dc,s);
    else{
        Board[tr+s-1][tc+s-1]=t;
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    if(dr<tr+s&&dc>=tc+s)
        ChessBoard(tr,tc+s,dr,dc,s);
    else{
        Board[tr+s-1][tc+s]=t;
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr>=tr+s&&dc<tc+s)
        ChessBoard(tr+s,tc,dr,dc,s);
    else{
        Board[tr+s][tc+s-1]=t;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    if(dr>=tr+s&&dc>=tc+s)
        ChessBoard(tr+s,tc+s,dr,dc,s);
    else{
        Board[tr+s][tc+s]=t;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }

}
void print(int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<Board[i][j]<<"     ";
            if(j==n-1)
                cout<<endl;
        }
    }
}
int main()
{
    int n,r,c;
    cin>>n;
    cin>>r>>c;
    ChessBoard(0,0,r,c,n);
    print(n);
    return 0;
}
