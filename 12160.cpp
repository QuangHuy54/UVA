#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
bool visited[10001];
long long res[10001];
int button[11];
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int l,u,n;
    int k;
    int c=0;
    while(scanf("%d %d %d",&l,&u,&n)&&(l||u||n)){
        int lock=l;
        int unlock=u;
        k=n;
        for(int i=0;i<k;i++){
            int s;
            scanf("%d",&s);
            button[i]=s;
        }
        memset(visited,0,sizeof(visited));
        memset(res,0,sizeof(res));
        queue<int> q;
        q.push(lock);
        visited[lock]=1;
        cout<<"Case "<<++c<<": ";
        bool flag=false;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<k;i++){
                int v=(u+button[i])%10000;
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                    res[v]=res[u]+1;
                    if(v==unlock){
                        cout<<res[v]<<"\n";
                        flag=true;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            cout<<"Permanently Locked"<<"\n";
        }
    }
    return 0;
}