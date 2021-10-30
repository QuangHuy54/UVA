#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> ar;
    int n,m,x,k,v;
    while(cin>>n>>m){
        ar.assign(1000000,vector<int>());
        for(int i=0;i<n;i++){
            cin>>x;
            ar[x].push_back(i);
        }
        while(m--){
            cin>>k>>v;
            if(k<=ar[v].size()){
                cout<<ar[v][k-1]+1<<"\n";
            }
            else{
                cout<<"0"<<"\n";
            }
        }
    }
    return 0;
}