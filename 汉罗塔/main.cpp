#include <iostream>

using namespace std;
void hanoi(int n,int a,int b,int c);
void show(int n,int a,int b);
int main()
{
    hanoi(3,1,2,3);
    return 0;
}
void hanoi(int n,int a,int b,int c){//表示的是从a移动到c，以b辅助
 if(n>0){
    hanoi(n-1,a,c,b);
    show(n,a,c);
    hanoi(n-1,b,a,c);
 }
}
//void hanoi(int n,int a,int b,int c){//表示的是从a移动到b，以c辅助
// if(n>0){
 //   hanoi(n-1,a,c,b);
 //   show(n,a,b);
 //   hanoi(n-1,c,b,a);
// }
//}
void show(int n,int a,int b){
    cout<<n<<":"<<a<<"->"<<b<<endl;
}
