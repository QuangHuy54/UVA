#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<string>
using namespace std;
int ans;
string s;
vector<stack<char>> container;
stack<char> emty;
void process(char c){
    for(int j=0;j<container.size();j++){
        if(c<=container[j].top()){
            container[j].push(c);
            return;
        }
    }
    container.push_back(emty);
    container[container.size()-1].push(c);
    ans++;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0;
    while(cin>>s&&s!="end"){
        container.clear();
        cout<<"Case "<<++t<<": ";
        ans=0;
        for(int i=0;i<s.size();i++){
            process(s[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}