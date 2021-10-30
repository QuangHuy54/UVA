#include<bits/stdc++.h>
using namespace std;
long long ar[27][27][352];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(ar,0,sizeof(ar));
    ar[0][0][0]=1;
    for(int i=1;i<=26;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<352;k++){
                ar[i][j][k]=ar[i-1][j][k];
                if(k-i>=0&&j>0){
                    ar[i][j][k]+=ar[i-1][j-1][k-i];
                }
            }
        }
    }
    int l,s,c=1;
    while(cin>>l>>s&&l&&s){
        cout<<"Case "<<c++<<": ";
        if(l>26||s>351){
            cout<<"0"<<"\n";
        }
        else{
        cout<<ar[26][l][s]<<"\n";
        }
    }
    return 0;
}