#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[100001];
    int c[109];
    int t,b,n;
    cin>>t;
    while(t--){
        cin>>b>>n;
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        for(int i=1;i<=30000;i++){
            a[i]=999999;
        }
        a[0]=0;
        for(int i=0;i<n;i++){
            for(int j=30000;j>=0;j--){
                    if(j-c[i]>=0){
                    a[j]=min(a[j-c[i]]+1,a[j]);
                    }
            }
        }
        for(int i=b;i<=30000;i++){
            if(a[i]<999999){
                cout<<i<<" "<<a[i]<<"\n";
                break;
            }
        }
    }
    return 0;
}