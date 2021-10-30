#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool visited[26];
vector<int> a[26];
void dfs(int s){
    if(visited[s]){
        return;
    }
    else{
        visited[s]=true;
        for(auto v:a[s]){
            dfs(v);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,tree,acorn;
    string s;
    cin>>t;
    while(t--){
        for(int i=0;i<26;i++){
            a[i].clear();
        }
        memset(visited,0,sizeof(visited));
        while(cin>>s&&s[0]!='*'){
            a[s[1]-'A'].push_back(s[3]-'A');
            a[s[3]-'A'].push_back(s[1]-'A');
        }
        cin>>s;
        tree=0;
        acorn=0;
        for(int i=0;i<s.size();i+=2){
            if(a[s[i]-'A'].empty()){
                acorn++;
            }
            else if(!visited[s[i]-'A']){
                dfs(s[i]-'A');
                tree++;
            }
        }
        cout<<"There are "<<tree<<" tree(s) and "<<acorn<<" acorn(s)."<<"\n";
    }
    return 0;
}