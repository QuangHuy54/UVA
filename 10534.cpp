#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a[10005];
    int LIS[10005];
    int DIS[10005];
    vector<int> Lis;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Lis.clear();
        for(int i=0;i<n;i++){
            int pos=lower_bound(Lis.begin(),Lis.end(),a[i])-Lis.begin();
            if(pos==Lis.size()){
                Lis.push_back(a[i]);
            }
            else{
                Lis[pos]=a[i];
            }
            LIS[i]=pos+1;
        }
        Lis.clear();
        reverse(a,a+n);
        for(int i=0;i<n;i++){
            int pos=lower_bound(Lis.begin(),Lis.end(),a[i])-Lis.begin();
            if(pos==Lis.size()){
                Lis.push_back(a[i]);
            }
            else{
                Lis[pos]=a[i];
            }
            DIS[i]=pos+1;
        }
        reverse(DIS,DIS+n);
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,2*min(DIS[i],LIS[i])-1);
        }
        cout<<res<<"\n";
    }
    return 0;
}