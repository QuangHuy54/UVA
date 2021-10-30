#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n,zeri,oni,res,ene,temp;
int color[245];
bool visited[245];
bool bipartite;
bool check(vector<int> graph[],int u){
    color[u]=1;
    queue<int> q;
    visited[u]=1;
    q.push(u);
    bipartite=true;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(int v:graph[k]){
            if(!visited[v]){
                visited[v]=1;
                color[v]=1-color[k];
                q.push(v);
            }
            else if(color[k]==color[v]){
                bipartite=false;
            }
        }
    }
    return bipartite;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> graph[204];
        for(int i=1;i<=n;i++){
            cin>>ene;
            for(int j=0;j<ene;j++){
                cin>>temp;
                graph[i].push_back(temp);
                graph[temp].push_back(i);
            }
        }
        res=0;
        temp=0;
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                memset(color,-1,sizeof(color));
                if(check(graph,i)){
                    zeri=0;
                    oni=0;
                    for(int i=1;i<=n;i++){
                        if(color[i]==1) {oni++;}
                        else if(color[i]==0) {zeri++;}
                    }
                    temp=max(oni,zeri);
                    res+=temp;
                }
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}