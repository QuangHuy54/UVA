#include<iostream>
using namespace std;
bool visited[102][102];
char a[102][102];
int n,t=0,res,m,x,y;
void floodfill(int r,int c){
    if(r<0||c<0||visited[r][c]||r>=m||c>=n||a[r][c]=='#'){
        return;
    }
    if(a[r][c]=='G'){
        res++;
    }
    visited[r][c]=true;
    if(r<m-1&&a[r+1][c]=='T') return;
    if(c<n-1&&a[r][c+1]=='T') return;
    if(r>0&&a[r-1][c]=='T') return;
    if(c>0&&a[r][c-1]=='T') return;
    floodfill(r+1,c);
    floodfill(r-1,c);
    floodfill(r,c+1);
    floodfill(r,c-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>m>>n){
        swap(m,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                if(a[i][j]=='P'){
                    x=i;
                    y=j;
                }
                visited[i][j]=0;
            }
        }
        res=0;
        floodfill(x,y);
        cout<<res<<"\n";
    }
    return 0;
}