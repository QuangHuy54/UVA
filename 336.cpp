#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<climits>
#include<queue>
#include<utility>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,u,v,c=0;
    while(cin>>n&&n){
        vector<int> graph[35];
        map<int,int> index;
        int t=1;
        for(int i=0;i<n;i++){
            cin>>u>>v;
            if(index.find(u)==index.end()){
                index[u]=t++;
            }
            if(index.find(v)==index.end()){
                index[v]=t++;
            }
            graph[index[u]].push_back(index[v]);
            graph[index[v]].push_back(index[u]);
        }
        int dist[32][32];
        memset(dist,0x3f3f3f3f,sizeof(dist));
        for(int i=1;i<t;i++){
            dist[i][i]=0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                u=q.front();
                q.pop();
                for(int v:graph[u]){
                    if(dist[i][v]==0x3f3f3f3f){
                        dist[i][v]=dist[i][u]+1;
                        q.push(v);
                    }
                }
            }
        }
        while(cin>>u>>v&&(u||v)){
            int idx=index[u],res=0;
            for(int i=1;i<t;i++){
                if(dist[idx][i]>v){
                    res++;
                }
            }
            cout<<"Case "<<++c<<": "<<res<<" nodes not reachable from node "<<u<<" with TTL = "<<v<<"."<<"\n";
        }
    }
    return 0;
}