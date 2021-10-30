#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int res;
vector<int> topo;
vector<int> graph[10002];
bool visited[10002];
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
    int a,b;
    int t;
    cin>>t;
    bool blank=false;
    int c=0;
    while(t--){
        cin>>n>>m;
        topo.clear();
        memset(visited,0,sizeof(visited));
        res=0;
        for(int i=1;i<=n;i++){
            graph[i].clear();
        }
        for(int i=0;i<m;++i){
            cin>>a>>b;
            graph[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                topoSort(i);
            }
        }
        reverse(topo.begin(),topo.end());
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++){
            if(!visited[topo[i]]){
                topoSort(topo[i]);
                res++;
            }
        }
        cout<<"Case "<<++c<<": "<<res<<"\n";
    }
    return 0;
}