#include<iostream>
#include<vector>
#include<climits>
#include<utility>
using namespace std;
vector<pair<int,int>> a[502];
bool visited[502];
int n,m,u,v,w,maxl,res;
int dfs(int u){
    visited[u]=true;
    int count=1;
    for(pair<int,int> v:a[u]){
        if(visited[v.first]==true||v.second!=maxl){
            continue;
        }
        visited[v.first]=true;
        count+=dfs(v.first);
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m&&(n||m)){
        maxl=INT_MIN;
        for(int i=1;i<=n;i++){
            a[i].clear();
            visited[i]=false;
        }
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            a[u].push_back(make_pair(v,w));
            a[v].push_back(make_pair(u,w));
            maxl=max(w,maxl);
        }
        res=0;
        for(int i=1;i<=n;i++){
            if(visited[i]==false){
                res=max(res,dfs(i));
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}