#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,t;
    long long x;
    long long f[21][21][21];
    int first=1;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        long long sum=0;
        memset(f,0,sizeof(f));
        if(first){
            first=0;
        }
        else{
            cout<<"\n";
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                for(int h=0;h<c;h++){
                    cin>>x;
                    if(i>0) x+=f[i-1][j][h];
                    if(j>0) x+=f[i][j-1][h];
                    if(h>0) x+=f[i][j][h-1];
                    if(i>0&&j>0) x-=f[i-1][j-1][h];
                    if(j>0&&h>0) x-=f[i][j-1][h-1];
                    if(i>0&&h>0) x-=f[i-1][j][h-1];
                    if(i>0&&j>0&&h>0) x+=f[i-1][j-1][h-1];
                    f[i][j][h]=x;
                }
            }
        }
        long long res=INT_MIN;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                for(int k=0;k<c;k++){
                    for(int i1=i;i1<a;i1++){
                        for(int j1=j;j1<b;j1++){
                            for(int k1=k;k1<c;k1++){
                                long long s=f[i1][j1][k1];
                                if(i>0) s-=f[i-1][j1][k1];
                                if(j>0) s-=f[i1][j-1][k1];
                                if(k>0) s-=f[i1][j1][k-1];
                                if(i>0&&j>0) s+=f[i-1][j-1][k1];
                                if(i>0&&k>0) s+=f[i-1][j1][k-1];
                                if(j>0&&k>0) s+=f[i1][j-1][k-1];
                                if(i>0&&j>0&&k>0) s-=f[i-1][j-1][k-1];
                                res=max(res,s);
                            }
                        }
                    }
                }
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}