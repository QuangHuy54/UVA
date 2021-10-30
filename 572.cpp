#include<iostream>
using namespace std;
bool visited[102][102];
char a[102][102];
int n,t=0,res,m;
void floodfill(int r,int c){
    if(r<0||c<0||visited[r][c]||r>=m||c>=n||a[r][c]!='@'){
        return;
    }
    visited[r][c]=true;
    floodfill(r+1,c);
    floodfill(r-1,c);
    floodfill(r,c+1);
    floodfill(r,c-1);
    floodfill(r+1,c+1);
    floodfill(r-1,c-1);
    floodfill(r+1,c-1);
    floodfill(r-1,c+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>m>>n&&(m||n)){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                visited[i][j]=0;
            }
        }
        res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&a[i][j]=='@'){
                    res++;
                    floodfill(i,j);
                }
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}