#include<iostream>
#include<string>
using namespace std;
bool visited[27][27];
bool a[27][27];
int n,t=0,res,temp,m;
void floodfill(int r,int c){
    if(r<0||c<0||visited[r][c]||r>=n||c>=m||a[r][c]!=1){
        return;
    }
    temp++;
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
    cin>>t;
    cin.ignore(100,'\n');
    cin.ignore(100,'\n');
    while(t--){
        n=0;
        while(getline(cin,s)){
            if(s=="") break;
            m=s.size();
            for(int i=0;i<m;i++){
                a[n][i]=s[i]-'0';
                visited[n][i]=false;
            }
            n++;
        }
        res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&a[i][j]==1){
                    temp=0;
                    floodfill(i,j);
                    res=max(res,temp);
                }
            }
        }
        cout<<res<<"\n";
        if(t){
            cout<<"\n";
        }
    }
    return 0;
}