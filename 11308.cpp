#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<string,long long> a,pair<string,long long> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,m,n,b,p,num,uni;
    string title,s,ele;
    map<string,int> price;
    cin>>t;      
    vector<pair<string,long long>> answ;
    while(t--){   
        cin.ignore();
        getline(cin,title);
        transform(title.begin(),title.end(),title.begin(),::toupper);
        price.clear();
        answ.clear();
        cin>>m>>n>>b;
        for(int i=0;i<m;i++){
            cin>>s>>p;
            price[s]=p;
        }
        for(int j=0;j<n;j++){
            cin.ignore();
            getline(cin,s);
            cin>>num;
            long long pricel=0;
            for(int k=0;k<num;k++){
                cin>>ele>>uni;
                pricel+=(long long)(uni*price[ele]);
            }
            if(pricel<=b){
                answ.push_back(make_pair(s,pricel));
            }
        }
        cout<<title<<"\n";
        if(answ.size()==0){
            cout<<"Too expensive!"<<"\n";
        }
        else{
            sort(answ.begin(),answ.end(),cmp);
            for(int i=0;i<answ.size();i++){
                cout<<answ[i].first<<"\n";
            }
        }
        cout<<"\n";
    }
    return 0;
}