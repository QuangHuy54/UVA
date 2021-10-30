#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a[10009];
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int sum=0;
        int res=0;
        for(int i=0;i<n;i++){
            if(sum+a[i]>0){
                sum+=a[i];
                res=max(res,sum);
            }
            else{
                sum=0;
            }
        }
        if(res<=0){
            cout<<"Losing streak."<<"\n";
        }
        else{
            cout<<"The maximum winning streak is "<<res<<"."<<"\n";
        }
    }
    return 0;
}