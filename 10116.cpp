#include<iostream>
#include<cstring>
using namespace std;
int n,m,k;
string a[13];
int step[12][12];
int coun;
bool visited[12][12];
bool loop;
int xend,yend;
int xloop,yloop;
void run(int x,int y){
    visited[x][y]=true;
    step[x][y]=coun;
    coun++;
    if(a[x][y]=='N'){
        if(x-1<0){
            return;
        }
        else if(visited[x-1][y]){
            loop=true;
            xloop=x-1;
            yloop=y;
            return;
        }
        else{
            run(x-1,y);
        }
    }
    if(a[x][y]=='E'){
        if(y+1>=m){
            return;
        }
        else if(visited[x][y+1]){
            loop=true;
            xloop=x;
            yloop=y+1;
            return;
        }
        else{
            run(x,y+1);
        }
    }
    if(a[x][y]=='W'){
        if(y-1<0){
            return;
        }
        else if(visited[x][y-1]){
            loop=true;
            xloop=x;
            yloop=y-1;
            return;
        }
        else{
            run(x,y-1);
        }
    }
    if(a[x][y]=='S'){
        if(x+1>=n){
            return;
        }
        else if(visited[x+1][y]){
            loop=true;
            xloop=x+1;
            yloop=y;
            return;
        }
        else{
            run(x+1,y);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m>>k&&(n||m||k)){
        k--;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        memset(step,0,sizeof(step));
        memset(visited,0,sizeof(visited));
        loop=false;
        coun=0;
        run(0,k);
        if(loop){
            cout<<step[xloop][yloop]<<" step(s) before a loop of "<<coun-step[xloop][yloop]<<" step(s)"<<"\n";
        }
        else{
            cout<<coun<<" step(s) to exit"<<"\n";
        }
    }
    return 0;
}