#include<iostream>
#include<map>
#include<string>
#include<cmath>
using namespace std;
int main(){
    int n,q,cp,c=0;
    string s;
    float price;
    map<string,int> mp;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        cin>>s>>price;
        price*=10;
        mp[s]=(int)price;
    }
    while(q--){
        int temp=0;
        while(cin>>s){
            if(s=="+"){
                continue;
            }
            if(s=="="){
                cin>>cp;
                if(temp==cp*10){
                    cout<<"Guess #"<<++c<<" was correct."<<"\n";
                }
                else{
                    cout<<"Guess #"<<++c<<" was incorrect."<<"\n";
                }
                break;
            }
            if(s==">"){
                cin>>cp;
                if(temp>cp*10){
                    cout<<"Guess #"<<++c<<" was correct."<<"\n";
                }
                else{
                    cout<<"Guess #"<<++c<<" was incorrect."<<"\n";
                }
                break;
            }
            if(s=="<"){
                cin>>cp;
                if(temp<cp*10){
                    cout<<"Guess #"<<++c<<" was correct."<<"\n";
                }
                else{
                    cout<<"Guess #"<<++c<<" was incorrect."<<"\n";
                }
                break;
            }
            if(s=="<="){
                cin>>cp;
                if(temp<=cp*10){
                    cout<<"Guess #"<<++c<<" was correct."<<"\n";
                }
                else{
                    cout<<"Guess #"<<++c<<" was incorrect."<<"\n";
                }
                break;
            }
            if(s==">="){
                cin>>cp;
                if(temp>=cp*10){
                    cout<<"Guess #"<<++c<<" was correct."<<"\n";
                }
                else{
                    cout<<"Guess #"<<++c<<" was incorrect."<<"\n";
                }
                break;
            }
            temp+=mp[s];
        }
    }
    return 0;
}