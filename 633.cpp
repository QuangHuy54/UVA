#include<iostream>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;
int row[12]={-1,-2,-2,-1,1,2,2,1};
int col[12]={-2,-1,1,2,2,1,-1,-2};
int row1[4]={2,2,-2,-2};
int col1[4]={2,-2,2,-2};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int dis[42][42][3];
    bool visited[42][42];
    while(cin>>n&&n){
        n*=2;
        int xa,ya,xb,yb;
        cin>>xa>>ya>>xb>>yb;
        int x,y;
        memset(visited,0,sizeof(visited));
        memset(dis,0x3f3f3f3f,sizeof(dis));
        dis[xa][ya][0]=0;
        dis[xa][ya][1]=0;
        dis[xa][ya][2]=0;
        while(cin>>x>>y&&(x||y)){
            visited[x][y]=true;
        }
        queue<pair<int,int>> bfs;
        queue<int> type;
        for(int i=0;i<3;i++){
            bfs.push(make_pair(xa,ya));
            type.push(i);
        }
        visited[xa][ya]=true;
        while(!bfs.empty()){
            pair<int,int> u=bfs.front();
            bfs.pop();
            int xu=u.first;
            int yu=u.second;
            int kind=type.front();
            type.pop();
            if(kind!=0){
                for(int i=0;i<8;i++){
                    if(xu+row[i]<=n&&xu+row[i]>=1&&yu+col[i]<=n&&yu+col[i]>=1){
                        if(!visited[xu+row[i]][yu+col[i]]){
                            if(dis[xu+row[i]][yu+col[i]][0]==0x3f3f3f3f){
                                dis[xu+row[i]][yu+col[i]][0]=dis[xu][yu][kind]+1;
                                bfs.push(make_pair(xu+row[i],yu+col[i]));
                                type.push(0);
                            }
                        }
                    }
                }
            }
            if(kind!=1){
                for(int i=0;i<4;i++){
                    if(xu+row1[i]<=n&&xu+row1[i]>=1&&yu+col1[i]<=n&&yu+col1[i]>=1){
                        if(!visited[xu+row1[i]][yu+col1[i]]){
                            if(dis[xu+row1[i]][yu+col1[i]][1]==0x3f3f3f3f){
                                dis[xu+row1[i]][yu+col1[i]][1]=dis[xu][yu][kind]+1;
                                bfs.push(make_pair(xu+row1[i],yu+col1[i]));
                                type.push(1);
                            }
                        }
                    }
                }
            }
            if(kind!=2){
                if(!visited[xu][n-yu+1]){
                    if(dis[xu][n-yu+1][2]==0x3f3f3f3f){
                        dis[xu][n-yu+1][2]=dis[xu][yu][kind]+1;
                        bfs.push(make_pair(xu,n-yu+1));
                        type.push(2);
                    }
                }
                if(!visited[n-xu+1][yu]){
                    if(dis[n-xu+1][yu][2]==0x3f3f3f3f){
                        dis[n-xu+1][yu][2]=dis[xu][yu][kind]+1;
                        bfs.push(make_pair(n-xu+1,yu));
                        type.push(2);
                    }
                }
            }
        }
        int res=0x3f3f3f3f;
        for(int i=0;i<3;i++){
            res=min(res,dis[xb][yb][i]);
        }
        if(res==0x3f3f3f3f){
            cout<<"Solution doesn't exist"<<"\n";
        }
        else{
            cout<<"Result : "<<res<<"\n";
        }
    }
    return 0;
}