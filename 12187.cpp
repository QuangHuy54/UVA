#include<iostream>
using namespace std;
int n,r,c,k;
int a[102][102];
int b[102][102];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>r>>c>>k&&(n||r||c||k)){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<k;i++){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    b[i][j]=a[i][j];
                }
            }
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    for(int t=0;t<4;t++){
                        if(i+dy[t]>=0&&i+dy[t]<r&&j+dx[t]>=0&&j+dx[t]<c){
                            if(b[i+dy[t]][j+dx[t]]==(b[i][j] == n-1 ? 0 : b[i][j]+1)){
                                a[i+dy[t]][j+dx[t]]=b[i][j];
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(j!=0){
                    cout<<" ";
                }
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
}