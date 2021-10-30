#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,c=0;
    string s,s1,s2;
    while(cin>>n&&n){
        map<string,int> index;
        string name[102];
        int degree[102];
        vector<vector<int>> graph(102);
        priority_queue<int,vector<int>, greater<int>> q;
        for(int i=0;i<n;i++){
            cin>>name[i];
            index[name[i]]=i;
            degree[i]=0;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>s1>>s2;
            graph[index[s1]].push_back(index[s2]);
            degree[index[s2]]++;
        }
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        cout<<"Case #"<<++c<<": Dilbert should drink beverages in this order:";
        while(!q.empty()){
            int u=q.top();
            q.pop();
            for(int v: graph[u]){
                if(--degree[v]==0){
                    q.push(v);
                }
            }
            cout<<" "<<name[u];
        }
        cout<<"."<<"\n";
        cout<<"\n";
    }
    return 0;
}