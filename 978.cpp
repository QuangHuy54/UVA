#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multiset<int> green;
    multiset<int> blue;
    vector<int> storeG;
    vector<int> storeB;
    int first=1;
    int t,b,sg,sb,x;
    cin>>t;
    while(t--){
        cin>>b>>sg>>sb;
        green.clear();
        blue.clear();
        storeG.clear();
        storeB.clear();
        for(int i=0;i<sg;i++){
            cin>>x;
            green.insert(x);
        }
        for(int i=0;i<sb;i++){
            cin>>x;
            blue.insert(x);
        }
        if(first){
            first=false;
        }
        else{
            cout<<"\n";
        }
        while(true){
            if(green.empty()||blue.empty()){
                break;
            }
            storeG.clear();
            storeB.clear();
            for(int i=0;i<b;i++){
                if(green.empty()||blue.empty()){
                    break;
                }
                auto it1=green.end();
                auto it2=blue.end();
                it1--;
                it2--;
                if(*it1>*it2){
                    green.erase(it1);
                    blue.erase(it2);
                    storeG.push_back(*it1-*it2); 
                }
                else if(*it2>*it1){
                    green.erase(it1);
                    blue.erase(it2);
                    storeB.push_back(*it2-*it1); 
                }
                else{
                    green.erase(it1);
                    blue.erase(it2);
                }
            }
            for(int i=0;i<storeG.size();i++){
                green.insert(storeG[i]);
            }
            for(int i=0;i<storeB.size();i++){
                blue.insert(storeB[i]);
            }
        }
        if(green.empty()&&blue.empty()){
            cout<<"green and blue died"<<"\n";
        }
        else if(green.empty()&&!blue.empty()){
            cout<<"blue wins"<<"\n";
            for(auto i=--blue.end();i!=blue.begin();i--){
                cout<<*i<<"\n";
            }
            cout<<*(blue.begin())<<"\n";
        }
        else{
            cout<<"green wins"<<"\n";
            for(auto i=--green.end();i!=green.begin();i--){
                cout<<*i<<"\n";
            }
            cout<<*(green.begin())<<"\n";
        }
    }
    return 0;
}