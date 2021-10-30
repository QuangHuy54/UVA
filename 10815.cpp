#include<set>
#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,r;
    set<string> ans;
    while(cin>>s){
        r="";
        for(int i=0;i<s.size();i++){
            if(isupper(s[i])){
                s[i]=tolower(s[i]);
            }
            if(islower(s[i])){
                r+=s[i];
            }
            else if(r!=""){
                ans.insert(r);
                r="";
            }
        }
        if(r!=""){
        ans.insert(r);
        }
    }
    for(auto it=ans.begin();it!=ans.end();it++){
            cout<<*it<<"\n";
        }
    return 0;
}