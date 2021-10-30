#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x;
    while(cin>>n&&n){
        multiset<int> ans;
        long long count=0;
        while(n--){
            cin>>k;
            for(int i=0;i<k;i++){
                cin>>x;
                ans.insert(x);
            }
            auto lowest=ans.begin();
            auto highest=--ans.end();
            count+=(*highest-*lowest);
            ans.erase(lowest);
            ans.erase(highest);
        }
        cout<<count<<"\n"; 
    }
    return 0;
}