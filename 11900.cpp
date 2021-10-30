#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,p,q,c=1;
    int a[31];
    cin>>t;
    while(t--){
        cin>>n>>p>>q;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int res=0;
        int answ=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+a[i]<=q){
                sum+=a[i];
                res++;
                answ=max(answ,res);
                if(res>=p){
                    answ=p;
                    break;
                }
            }
            else{
                if(a[i]<=q){
                sum=a[i];
                answ=max(answ,res);
                res=1;
                }
            }
        }
        cout<<"Case "<<c<<": "<<answ<<"\n";
        c++;
    }
    return 0;
}