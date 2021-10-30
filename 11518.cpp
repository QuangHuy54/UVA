#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool visited[10001];
vector<int> a[10001];
int res;
void dfs(int i){
    if(visited[i]){
        return;
    }
    else{
        res++;
        visited[i]=true;
        for(auto j: a[i]){
            dfs(j);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,l,x,y,temp;
    cin>>t;
    while(t--){
        cin>>n>>m>>l;
        for(int i=1;i<=n;i++){
            a[i].clear();
        }
        while(m--){
            cin>>x>>y;
            a[x].push_back(y);
        } 
        memset(visited,0,sizeof(visited));
        res=0;
        while(l--){
            cin>>temp;
            dfs(temp);
        }
        cout<<res<<"\n";
    }
    return 0;
}