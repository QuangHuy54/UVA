#include<iostream>
#include<stack>
#include<string>
using namespace std;
int ranking(char c){
    if(c=='('||c==')'){
        return 1;
    }
    if(c=='+'||c=='-'){
        return 2;
    }
    if(c=='*'||c=='/'){
        return 3;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string in,out;
    stack<char> a;
    string s;
    cin>>t;
    int first=1;
    cin.ignore();
    cin.ignore();
    while(t--){
        in="";
        while(getline(cin,s)){
            if(s.size()==0){
                break;
            }
            in+=s;
        }
        out="";
        for(int i=0;i<in.size();i++){
            if(in[i]>='0'&&in[i]<='9'){
                out+=in[i];
            }
            else if(in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/'){
                while(!a.empty()&&ranking(in[i])<=ranking(a.top())){
                    out+=a.top();
                    a.pop();
                }
                a.push(in[i]);
            }
            else if(in[i]=='('){
                a.push(in[i]);
            }
            else{
                while(a.top()!='('){
                    out+=a.top();
                    a.pop();
                }
                a.pop();
            }
        }
        while(!a.empty()){
            out+=a.top();
            a.pop();
        }
        if(first){
            first=0;
        }
        else{
            cout<<"\n";
        }
        cout<<out<<"\n";
    }
    return 0;
}