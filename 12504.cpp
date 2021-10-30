#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string old,neww;
    int t;
    cin>>t;
    while(t--){
        cin>>old>>neww;
        string key,val;
        map<string,string> ol,ne;
        bool change=false;
        for(int i=1;i<old.size();i++){
            key="";
            val="";
            while(old[i]!=':'&&old[i]!='}'){
                key.push_back(old[i]);
                i++;
            }
            i++;
            if(i>=old.size()){
                break;
            }
            while(old[i]!=','&&old[i]!='}'){
                val.push_back(old[i]);
                i++;
            }
            ol[key]=val;
        }
        for(int i=1;i<neww.size();i++){
            key="";
            val="";
            while(neww[i]!=':'&&neww[i]!='}'){
                key.push_back(neww[i]);
                i++;
            }
            i++;
            if(i>=neww.size()){
                break;
            }
            while(neww[i]!=','&&neww[i]!='}'){
                val.push_back(neww[i]);
                i++;
            }
            ne[key]=val;
        }
        bool flag=false;
        for(auto i=ne.begin();i!=ne.end();i++){
            if(ol.find(i->first)==ol.end()){
                if(!flag){
                    cout<<"+";
                }
                else{
                    cout<<",";
                }
                cout<<i->first;
                flag=true;
            }
        }
        if(flag){
            cout<<"\n";
            change=true;
        }
        flag=false;
        for(auto i=ol.begin();i!=ol.end();i++){
            if(ne.find(i->first)==ne.end()){
                if(!flag){
                    cout<<"-";
                }
                else{
                    cout<<",";
                }
                cout<<i->first;
                flag=true;
            }
        }
        if(flag){
            cout<<"\n";
            change=true;
        }
        flag=false;
        for(auto i=ne.begin();i!=ne.end();i++){
            if(ol.find(i->first)!=ol.end()){
                if(i->second!=ol[i->first]){
                if(!flag){
                    cout<<"*";
                }
                else{
                    cout<<",";
                }
                cout<<i->first;
                flag=true;
                }
            }
        }
        if(flag){
            cout<<"\n";
            change=true;
        }
        if(!change){
            cout<<"No changes"<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}