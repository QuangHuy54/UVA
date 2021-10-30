#include<bits/stdc++.h>
using namespace std;
long long res[66][66][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s,n;
    res[1][1][1]=1;
    res[1][0][0]=1;
    for(int i=2;i<=65;i++){
        for(int j=0;j<=65;j++){
            if(j>i){
                res[i][j][0]=0;
                res[i][j][1]=0;
            }
            else if(i==j){
                res[i][j][1]=1;
                res[i][j][0]=0;
            }
            else{
                res[i][j][0]=res[i-1][j][1]+res[i-1][j][0];
                res[i][j][1]=res[i-1][j][0]+res[i-1][j-1][1];
            }
        }
    }
    while(cin>>n>>s&&(n>=0)&&(s>=0)){
        cout<<res[n][s][1]+res[n][s][0]<<"\n";
    }
    return 0;
}