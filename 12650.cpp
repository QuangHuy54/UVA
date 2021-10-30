#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,r,x;
    bool a[10005];
    while(cin>>n>>r){
        for(int i=1;i<=n;i++){
            a[i]=false;
        }
        for(int i=1;i<=r;i++){
            cin>>x;
            a[x]=true;
        }
        if(n==r){
            cout<<"*"<<"\n";
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==false){
                    cout<<i<<" ";
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}