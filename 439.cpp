#include<iostream>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;
int row[8]={-1,-2,-2,-1,1,2,2,1};
int col[8]={-2,-1,1,2,2,1,-1,-2};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    int dis[9][9];
    bool visited[9][9];
    while(cin>>a>>b){
        int ya=a[0]-'a'+1;
        int xa=a[1]-'0';
        int yb=b[0]-'a'+1;
        int xb=b[1]-'0';
        dis[xa][ya]=0;
        memset(visited,0,sizeof(visited));
        memset(dis,0x3f3f3f3f,sizeof(dis));
        queue<pair<int,int>> bfs;
        bfs.push(make_pair(xa,ya));
        visited[xa][ya]=true;
        dis[xa][ya]=0;
        while(!bfs.empty()){
            pair<int,int> u=bfs.front();
            bfs.pop();
            int xu=u.first;
            int yu=u.second;
            int res=0;
            for(int i=0;i<8;i++){
                if(xu+row[i]<=8&&xu+row[i]>=1&&yu+col[i]<=8&&yu+col[i]>=1){
                    if(!visited[xu+row[i]][yu+col[i]]){
                        dis[xu+row[i]][yu+col[i]]=dis[xu][yu]+1;
                        visited[xu+row[i]][yu+col[i]]=true;
                        if(xu+row[i]==xb&&yu+col[i]==yb){
                            break;
                        }
                        bfs.push(make_pair(xu+row[i],yu+col[i]));
                    }
                }
            }
        }
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<dis[xb][yb]<<" knight moves."<<"\n";
    }
    return 0;
}