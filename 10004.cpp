#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n,u,v,l;
int color[203];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n&&n){
        vector<vector<int>> graph(n);
        cin>>l;
        for(int i=0;i<l;++i){
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<int> q;
        memset(color,-1,sizeof(color));
        bool res=true;
        q.push(0);
        color[0]=1;
        while(!q.empty()&&res){
            u=q.front();
            q.pop();
            for(int v: graph[u]){
                if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
                else if(color[v]==color[u]){
                    res=false;
                    break;
                }
            }
        }
        if(res){
            cout<<"BICOLORABLE."<<"\n";
        }
        else{
            cout<<"NOT BICOLORABLE."<<"\n";
        }
    }
    return 0;
}