#include<bits/stdc++.h>
using namespace std;
bool ok(char a,char b){
    return (a-'0'+b-'0')<=3;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s1,s2;
    while(cin>>s1>>s2){
        int answ=s1.size()+s2.size();
        int len1=s1.size();
        int len2=s2.size();
        int l=0;
        for(int i=0;i<s1.size();i++){
            bool okl=true;
            int j=0;
            for(j=0;j<s2.size()&&i+j<s1.size();j++){
                if(!ok(s1[i+j],s2[j])){
                    okl=false;
                    break;
                }
            }
            if(okl){
                answ=min(answ,len1+len2-j);
                break;
            }
        }
        for(int i=0;i<s2.size();i++){
            bool okl=true;
            int j=0;
            for(j=0;j<s1.size()&&i+j<s2.size();j++){
                if(!ok(s2[i+j],s1[j])){
                    okl=false;
                    break;
                }
            }
            if(okl){
                answ=min(answ,len1+len2-j);
                break;
            }
        }
        cout<<answ<<"\n";
    }
    return 0;
}