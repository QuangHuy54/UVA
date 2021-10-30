#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
int n;
string vertex;
vector<vector<int>> graph(28);
vector<int> res;
bool visited[28];
int degree[28];
bool ok;
void solve(){
    for(int i=0;i<n;i++){
        if(degree[vertex[i]-'A']==0&&!visited[i]){
            for(int u:graph[vertex[i]-'A']){
                degree[u]--;
            }
            res.push_back(i);
            visited[i]=true;
            solve();
            for(int u:graph[vertex[i]-'A']){
                degree[u]++;
            }        
            res.pop_back();
            visited[i]=false;
        }
    }
    if(res.size()==n){  
        ok=true;
        for(int i=0;i<n;i++){
            if(i>0){
                cout<<" ";
            }
            cout<<vertex[res[i]];
        }
        cout<<"\n";
    }
}
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    string temp;
    while(t--){
        getchar();
        getline(cin,s);
        stringstream ss;
        graph.clear();
        res.clear();
        ss<<s;
        vertex="";
        while(ss>>temp){
            vertex+=temp;
        }
        sort(vertex.begin(),vertex.end());
        n=vertex.size();
        getline(cin,s);
        ss.clear();
        ss<<s;
        memset(degree,0,sizeof(degree));
        memset(visited,0,sizeof(visited));
        while(ss>>temp){
            graph[temp[0]-'A'].push_back(temp[2]-'A');
            degree[temp[2]-'A']++;
        }
        ok=false;
        solve();
        if(!ok){
            cout<<"NO"<<"\n";
        }
        if(t){
            cout<<"\n";
        }
    }
    return 0;
}