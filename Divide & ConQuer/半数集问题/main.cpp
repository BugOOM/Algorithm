#include <iostream>

using namespace std;
long Set(int n){
    long ans=1;
    if(n>1)
        for(int i=1;i<=n/2;i++){
        ans+=Set(i);
    }
    return ans;
}
int main()
{
    cout << Set(6)<< endl;
    return 0;
}
