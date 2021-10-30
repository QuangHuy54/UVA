#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<sstream>
#include<cstring>
#include<vector>
using namespace std;
int dist[205];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    cin>>t;
    while(t--){
        vector<int> graph[205];
        map<string,int> index;
        vector<string> ar;
        int k=0;
        while(cin>>s&&s!="*"){
            ar.push_back(s);
            index[s]=k++;
        }
        cin.ignore();
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(i==j||ar[i].size()!=ar[j].size()){continue;}
                int uncommon=0;
                for(int k=0;k<ar[i].size();k++){
                    if(ar[i][k]!=ar[j][k]){uncommon++;}
                }
                if(uncommon==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        while(getline(cin,s)&&s!=""){
            stringstream ss(s);
            string a,b;
            ss>>a>>b;
            memset(dist,0x3f3f3f3f,sizeof(dist));
            int u=index[a],v=index[b];
            dist[u]=0;
            queue<int> q;
            q.push(u);
            bool exit=false;
            while(!q.empty()){
                int k=q.front();
                q.pop();
                for(int m:graph[k]){
                    if(dist[m]==0x3f3f3f3f){
                        dist[m]=dist[k]+1;
                        if(m==v){
                            exit=true;
                            break;
                        }
                        q.push(m);
                    }
                }
                if(exit){
                    break;
                }
            }
            cout<<a<<" "<<b<<" "<<dist[v]<<"\n";
        }
        if(t){
            cout<<"\n";
        }
    }
    return 0;
}