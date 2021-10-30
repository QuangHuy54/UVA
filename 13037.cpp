#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> Le;
    set<int> Ro;
    set<int> Su;
    int c=1;
    int result[11];
    int t,l,r,s,x;
    cin>>t;
    while(t--){
        Le.clear();
        Ro.clear();
        Su.clear();
        memset(result,0,sizeof(result));
        cin>>l>>r>>s;
        for(int i=0;i<l;i++){
            cin>>x;
            Le.insert(x);
        }
        for(int i=0;i<r;i++){
            cin>>x;
            Ro.insert(x);
        }
        for(int i=0;i<s;i++){
            cin>>x;
            Su.insert(x);
        }
        cout<<"Case #"<<c<<":"<<"\n";
        c++;
        for(auto& i:Le){
            if(Ro.count(i)==0&&Su.count(i)==0){
                result[0]++;
            }
            else if(Ro.count(i)==0&&Su.count(i)!=0){
                result[3]++;
            }
            else if(Su.count(i)==0&&Ro.count(i)!=0){
                result[5]++;
            }
        }
        for(auto& i:Ro){
            if(Le.count(i)==0&&Su.count(i)==0){
                result[2]++;
            }
            else if(Le.count(i)==0&&Su.count(i)!=0){
                result[1]++;
            }
            else if(Su.count(i)==0&&Le.count(i)!=0){
                result[5]++;
            }
        }
        for(auto& i:Su){
            if(Le.count(i)==0&&Ro.count(i)==0){
                result[4]++;
            }
            else if(Le.count(i)==0&&Ro.count(i)!=0){
                result[1]++;
            }
            else if(Ro.count(i)==0&&Le.count(i)!=0){
                result[3]++;
            }
        }
        for(int i=0;i<6;i+=2){
            cout<<result[i]<<" "<<result[i+1]/2<<"\n";
        }
    }
    return 0;
}