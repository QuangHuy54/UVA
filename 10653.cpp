#include<iostream>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;
int graph[1002][1002];
int res[1002][1002];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,c;
    while(cin>>r>>c&&(r||c)){
        memset(graph,0,sizeof(graph));
        memset(res,0x3f3f3f3f,sizeof(res));
        int row;
        cin>>row;
        while(row--){
            int u,k;
            cin>>u>>k;
            while(k--){
                int v;
                cin>>v;
                graph[u][v]=1;
            }
        }
        int xstart,ystart,xend,yend;
        cin>>xstart>>ystart>>xend>>yend;
        res[xstart][ystart]=0;
        queue<int> q;
        q.push(xstart);
        q.push(ystart);
        int stop=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            int y=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xt=x+dx[i];
                int yt=y+dy[i];
                if(xt>=0&&yt>=0&&xt<r&&yt<c&&res[xt][yt]==0x3f3f3f3f&&graph[xt][yt]!=1){
                    res[xt][yt]=res[x][y]+1;
                    if(xt==xend&&yt==yend){
                        cout<<res[xt][yt]<<"\n";
                        stop=1;
                        break;
                    }
                    else{
                        q.push(xt);
                        q.push(yt);
                    }
                }
            }
            if(stop){
                break;
            }
        }
    }
    return 0;
}