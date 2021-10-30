#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,w;
    int a[100005];
    long long sum;
    cin>>t;
    while(t--){
        cin>>n>>w;
        sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int res=0;
        for(int i=0;i<n;i++){
            if(sum+a[i]<=w){
                sum+=a[i];
                res++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}