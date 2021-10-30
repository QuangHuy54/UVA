#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<cstring>
using namespace std;
int res;
vector<int> graph[2002];
int low[2002],num[2002],timer;
bool visited[2002];
vector<int> s;
void SCC(int u){
    low[u]=num[u]=++timer;
    visited[u]=true;
    s.push_back(u);
    for(int v:graph[u]){
        if(num[v]==-1){
            SCC(v);
        }
        if(visited[v]){
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==num[u]){
        bool first=true;
        while(true){
            int v=s.back();
            s.pop_back();
            visited[v]=false;
            if(u==v){break;}
        }
        res++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,index;
    int u,v,k;
    bool blank=false;
    int c=0;
    while(cin>>n>>m&&(n||m)){
        s.clear();
        memset(num,-1,sizeof(num));
        memset(low,0,sizeof(low));
        memset(visited,0,sizeof(visited));
        timer=0;
        res=0;
        for(int i=1;i<=n;i++){
            graph[i].clear();
        }
        for(int i=0;i<m;++i){
            cin>>u>>v>>k;
            graph[u].push_back(v);
            if(k==2){
                graph[v].push_back(u);
            }
            
        }
        for(int i=1;i<=n;i++){
            if(num[i]==-1){
                SCC(i);
            }
        }
        res=res>1 ? 0 : 1;
        cout<<res<<"\n";
    }
    return 0;
}