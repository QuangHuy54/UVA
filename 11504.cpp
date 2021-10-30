#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> topo;
vector<int> graph[100002];
bool visited[100002];
void topoSort(int u){
    visited[u]=true;
    for(int v:graph[u]){
        if(!visited[v]){
            topoSort(v);
        }
    }
    topo.push_back(u);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,index;
    string a,b;
    int t;
    cin>>t;
    int u,v,res;
    int c=0;
    while(t--){
        cin>>n>>m;
        topo.clear();
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;i++){
            graph[i].clear();
        }
        for(int i=0;i<m;++i){
            cin>>u>>v;
            graph[u].push_back(v);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                topoSort(i);
            }
        }
        reverse(topo.begin(),topo.end());
        res=0;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;++i){
            if(!visited[topo[i]]){
                topoSort(topo[i]);
                res++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}