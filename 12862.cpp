#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;
int total,largest;
bool fr[100004];
vector<pair<int,int>> a[100004];
void dfs(int u,int& friends,int d){
    int ff=0,v;
    friends=fr[u];
    if(fr[u]){
        largest=max(largest,d);
    }
    for(int i=0;i<a[u].size();i++){
        v=a[u][i].first;
        dfs(v,ff,d+a[u][i].second);
        if(ff>0){
            total+=a[u][i].second;
            friends+=ff;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,f;
    while(cin>>n>>f){
        for(int i=1;i<=n;i++){
            a[i].clear();
            fr[i]=0;
        }
        int x,y,d;
        for(int i=0;i<n-1;i++){
            cin>>x>>y>>d;
            a[x].push_back(make_pair(y,d));
        }
        for(int i=0;i<f;i++){
            cin>>x;
            fr[x]=1;
        }
        total=0;
        largest=0;
        dfs(1,x,0);
        cout<<total-largest<<"\n";
    }
    return 0;
}