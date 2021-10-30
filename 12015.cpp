#include<bits/stdc++.h>
using namespace std;
struct web{
    string link;
    int relevant;
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    web a[11];
    int t,res;
    cin>>t;
    int c=1;
    while(t--){
        res=-1;
        for(int i=0;i<10;i++){
            cin>>a[i].link>>a[i].relevant;
            res=max(res,a[i].relevant);
        }
        cout<<"Case #"<<c++<<":"<<"\n";
        for(int i=0;i<10;i++){
            if(res==a[i].relevant){
                cout<<a[i].link<<"\n";
            }
        }
    }
    return 0;
}