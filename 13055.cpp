#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<string> dream;
    int t;
    cin>>t;
    string s;
    string person;
    while(t--){
        cin>>s;
        if(s=="Sleep"){
            cin>>person;
            dream.push(person);
        }
        else if(s=="Test"){
            if(dream.empty()){
                cout<<"Not in a dream"<<"\n";
            }
            else{
                cout<<dream.top()<<"\n";
            }
        }
        else if(s=="Kick"){
            if(dream.empty()){
                continue;
            }
            else{
                dream.pop();
            }
        }
    }
    return 0;
}