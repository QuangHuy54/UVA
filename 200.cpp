#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> graph(28);
bool visited[27];
bool exist[27];
int degree[27];
vector<int> res;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,prev;
    cin>>prev;
    while(cin>>s&&s!="#"){
        for(int i=0;i<s.size()&&i<prev.size();i++){
            if(s[i]!=prev[i]){
                exist[s[i]-'A']=1;
                exist[prev[i]-'A']=1;
                graph[prev[i]-'A'].push_back(s[i]-'A');
                break;
            }
        }
        prev=s;
    }
    for(int i=0;i<26;i++){
        if(graph[i].empty()){
            continue;
        }
        for(int u: graph[i]){
            degree[u]++;
        }
    }
    queue<int> q;
    for(int i=0;i<26;i++){
        if(exist[i]&&degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        res.push_back(u);
        for(int v:graph[u]){
            if(--degree[v]==0){
                q.push(v);
            }
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<(char)(res[i]+'A');
    }
    cout<<"\n";
    return 0;
}