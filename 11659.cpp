#include<iostream>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok[21];
    int n,a,x,y,temp;
    while(cin>>n>>a&&(n||a)){
        for(int i=1;i<=n;i++){
            ok[i]=true;
        }
        temp=0;
        for(int i=0;i<a;i++){
            cin>>x>>y;
            if(y<0){
                y*=-1;
                if(ok[y]){
                    ok[y]=false;
                    temp++;
                }
            }
        }
        cout<<n-temp<<"\n";

    }
    return 0;
}