#include<iostream>
#include<vector>
#include<string>
using namespace std;
void dfs(vector<bool> &visited,vector<vector<int>> graph,int x){
    if(visited[x]){
        return;
    }
    visited[x]=true;
    for(int u: graph[x]){
        if(!visited[u]){
            dfs(visited,graph,u);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int res,t,n,first=1;
    string s;
    cin>>t;
    char top;
    while(t--){
        cin>>top;
        n=top-'A'+1;
        cin.ignore();
        vector<vector<int>> graph(n);
        vector<bool> visited(n,false);
        while(getline(cin,s)){
            if(s.size()==0){
                break;
            }
            graph[s[0]-'A'].push_back(s[1]-'A');
            graph[s[1]-'A'].push_back(s[0]-'A');
        }
        res=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                res++;
                dfs(visited,graph,i);
            }
        }
        if(first){
            first=0;
        }
        else{
            cout<<"\n";
        }
        cout<<res<<"\n";
    }
    return 0;
}