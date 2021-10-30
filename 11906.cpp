#include<iostream>
#include<cstring>
using namespace std;
int a[101][101],r,c,m,n,w,x,y,sum,even,odd,v=0;
void dfs(int x,int y){
    if(a[x][y]!=0){
        return;
    }
    else{
        a[x][y]=1;
        if(x+m<r&&y+n<c){
            dfs(x+m,y+n);
        }
        if(x-m>=0&&y-n>=0){
            dfs(x-m,y-n);
        }
        if(x+m<r&&y-n>=0){
            dfs(x+m,y-n);
        }
        if(x-m>=0&&y+n<c){
            dfs(x-m,y+n);
        }
        if(x+n<r&&y+m<c){
            dfs(x+n,y+m);
        }
        if(x+n<r&&y-m>=0){
            dfs(x+n,y-m);
        }
        if(x-n>=0&&y+m<c){
            dfs(x-n,y+m);
        }
        if(x-n>=0&&y-m>=0){
            dfs(x-n,y-m);
        }
    }
}
void solve(int x,int y,int& sum,int k){
    if(a[x][y]==-1){
        return;
    }
    else if(k==1){
        if(a[x][y]==1){
            sum++;
        }
        return;
    }
    else{
        if(x+m<r&&y+n<c){
            solve(x+m,y+n,sum,1);
        }
        if(x-m>=0&&y-n>=0){
            solve(x-m,y-n,sum,1);
        }
        if(x+m<r&&y-n>=0){
            solve(x+m,y-n,sum,1);
        }
        if(x-m>=0&&y+n<c){
            solve(x-m,y+n,sum,1);
        }
        if(x+n<r&&y+m<c){
            solve(x+n,y+m,sum,1);
        }
        if(x+n<r&&y-m>=0){
            solve(x+n,y-m,sum,1);
        }
        if(x-n>=0&&y+m<c){
            solve(x-n,y+m,sum,1);
        }
        if(x-n>=0&&y-m>=0){
            solve(x-n,y-m,sum,1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>r>>c>>m>>n;
        memset(a,0,sizeof(a));
        cin>>w;
        for(int i=0;i<w;i++){
            cin>>x>>y;
            a[x][y]=-1;
        }
        even=odd=0;
        dfs(0,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==1){
                    sum=0;
                    solve(i,j,sum,0);
                    if(m==n||m==0||n==0){
                        sum/=2;
                    }
                    if(sum%2==0){
                        even++;
                    }
                    else if(sum%2==1){
                        odd++;
                    }
                }
            }
        }
        cout<<"Case "<<++v<<": "<<even<<" "<<odd<<"\n";
    }
    return 0;
}