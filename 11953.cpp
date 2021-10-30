#include<iostream>
using namespace std;
int n;
char a[102][102];
bool visited[102][102];
void floodfill(int r,int c){
    if(r<0||c<0||r>=n||c>=n||visited[r][c]||a[r][c]=='.'){
        return;
    }
    visited[r][c]=true;
    floodfill(r+1,c);
    floodfill(r-1,c);
    floodfill(r,c+1);
    floodfill(r,c-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,res,c=0;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                visited[i][j]=false;
            }
        }
        res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&a[i][j]=='x'){
                    res++;
                    floodfill(i,j);
                }
            }
        }
        cout<<"Case "<<++c<<": "<<res<<"\n";
    }
    return 0;
}