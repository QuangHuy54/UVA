#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<cstring>
using namespace std;
map<string,int> vt;
string ar[27];
vector<vector<int>> res;
vector<int> graph[27];
int low[27],num[27],timer;
bool visited[27];
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
            if(first){
                first=false;
            }
            else{
                cout<<", ";
            }
            cout<<ar[v];
            s.pop_back();
            visited[v]=false;
            if(u==v){break;}
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,index;
    string a,b;
    bool blank=false;
    int c=0;
    while(cin>>n>>m&&(n||m)){
        if(!blank){
            blank=1;
        }
        else{
            cout<<"\n";
        }
        vt.clear();
        res.clear();
        s.clear();
        memset(num,-1,sizeof(num));
        memset(low,0,sizeof(low));
        memset(visited,0,sizeof(visited));
        timer=0;
        index=0;
        for(int i=1;i<=n;i++){
            graph[i].clear();
        }
        for(int i=0;i<m;++i){
            cin>>a>>b;
            if(vt.find(a)==vt.end()){
                vt[a]=++index;
                ar[index]=a;
            }
            if(vt.find(b)==vt.end()){
                vt[b]=++index;
                ar[index]=b;
            }
            graph[vt[a]].push_back(vt[b]);
        }
        cout<<"Calling circles for data set "<<++c<<":"<<"\n";
        for(int i=1;i<=n;i++){
            if(num[i]==-1){
                SCC(i);
            }
        }
    }
    return 0;
}