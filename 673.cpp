#include<bits/stdc++.h>
using namespace std;
bool matched(char c,char d){
    if(c=='('){
        return d==')';
    }
    else{
        return d==']';
    }
}
bool solve(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['){
            st.push(s[i]);
        } 
        else{
        if(st.empty()){
            return false;
        }
        if((s[i]==']'||s[i]==')')&&!matched(st.top(),s[i])){
            return false;
        }
        st.pop();
        }
    }
    if(st.empty()){
    return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    bool first=true;
    string s;
    cin>>t;
    cin.ignore();
    while(t--){
        getline(cin,s);
        bool ok=solve(s);
        if(s.empty()){
            ok=true;
        }
        if(ok){
            cout<<"Yes"<<"\n";
        }
        else{
            cout<<"No"<<"\n";
        }
    }
}