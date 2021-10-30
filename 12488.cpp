#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a[25],b[25],res,j,i,k;
    while(cin>>n){
        for(i=0;i<n;++i){
            cin>>a[i];
        }
        for(i=0;i<n;++i){
            cin>>b[i];
        }
        res=0;
        for(i=0;i<n;++i){
            for(j=i;j<n;++j){
                if(b[i]==a[j]){
                    break;
                }
            }
            for(k=j;k>i;--k){
                a[k]=a[k-1];
                res++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}