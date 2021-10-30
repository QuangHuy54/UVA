#include<iostream>
using namespace std;
bool visited[102][102];
char a[102][102];
char colour;
int n,t=0,res,m,x,y,temp;
void floodfill(int r,int c){
    if(r<0||c<0||visited[r][c]||r>=m||c>=n||a[r][c]!=colour){
        return;
    }
    temp++;
    visited[r][c]=true;
    floodfill(r+1,c);
    floodfill(r-1,c);
    if(c+1==n){
        floodfill(r,0);
    }
    else{
        floodfill(r,c+1);
    }
    if(c-1<0){
        floodfill(r,n-1);
    }
    else{
        floodfill(r,c-1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>m>>n){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                visited[i][j]=0;
            }
        }
        cin>>x>>y;
        colour=a[x][y];
        res=0;
        floodfill(x,y);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&a[i][j]==colour){
                    temp=0;
                    floodfill(i,j);
                    res=max(res,temp);
                }
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}