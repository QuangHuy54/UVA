#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,temp;
    string s,res;
    map<string,int> a;
    while(cin>>n>>s){
        a.clear();
        for(int i=0;i<=s.size()-n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp.push_back(s[i+j]);
            }
            if(a.find(temp)==a.end()){
                a.insert(pair<string,int>(temp,1));
            }
            else{
                a[temp]++;
            }
        }
        temp=0;
        for(auto i=a.begin();i!=a.end();i++){
            if((i->second)>temp){
                temp=i->second;
                res=i->first;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}