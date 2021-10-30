#include<iostream>
using namespace std;
bool visited[27][27];
bool a[27][27];
int n,t=0,res;
void floodfill(int r,int c){
    if(r<0||c<0||visited[r][c]||r>=n||c>=n||a[r][c]!=1){
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
    string s;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<n;j++){
                a[i][j]=s[j]-'0';
                visited[i][j]=0;
            }
        }
        res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&a[i][j]==1){
                    res++;
                    floodfill(i,j);
                }
            }
        }
        cout<<"Image number "<<++t<<" contains "<<res<<" war eagles."<<"\n";
    }
    return 0;
}