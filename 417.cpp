#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> mp;
int res=0;
void process(string s,int len){
    if(s.size()==len){
        mp[s]=++res;
        return;
    }
    char last;
    if(s.empty()){
        last='a';
    }
    else{
        last=s[s.size()-1]+1;
    }
    for(char c=last;c<='z';c++){
        process(s+c,len);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    for(int i=1;i<=5;i++){
        process("",i);
    }
    while(cin>>s){
        cout<<mp[s]<<"\n";
    }
    return 0;
}