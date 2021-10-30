#include<bits/stdc++.h>
using namespace std;
struct player{
    string name;
    int attack;
    int defend;
};
bool compare(player a,player b){
    if(a.attack==b.attack){
        if(a.defend==b.defend){
            return a.name<b.name;
        }
        return a.defend<b.defend;
    }
    return a.attack>b.attack;
}
bool cp(player a,player b){
    return a.name<b.name;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    player a[10];
    int t,c=1;
    cin>>t;
    while(t--){
        for(int i=0;i<10;i++){
            cin>>a[i].name>>a[i].attack>>a[i].defend;
        }
        sort(a,a+10,compare);
        sort(a,a+5,cp);
        sort(a+5,a+10,cp); 
        cout<<"Case "<<c++<<":"<<"\n";
        cout<<"(";
        for(int i=0;i<5;i++){
            if(i==4){
                cout<<a[i].name<<")"<<"\n";
            }
            else{
            cout<<a[i].name<<", ";
            }
        }
        cout<<"(";
        for(int i=5;i<10;i++){
            if(i==9){
                cout<<a[i].name<<")"<<"\n";
            }
            else{
            cout<<a[i].name<<", ";
            }
        }
    }
    return 0;
}