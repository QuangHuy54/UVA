#include<iostream>
#include<string>
#include<climits>
#include<sstream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,word;
    int n,w[31],c,flag;
    while(getline(cin,s)&&s!=""){
        stringstream str(s);
        n=0;
        c=INT_MAX;
        while(str>>word){
            w[n]=0;
            for(int i=0;i<word.size();i++){
                w[n]=(w[n]<<5)+(word[i]-'a'+1);
            }
            c=min(c,w[n]);
            n++;
        }
        while(true){
            flag=1;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if((c/w[i])%n==(c/w[j])%n){
                        c=min(((c/w[i])+1)*w[i],((c/w[j])+1)*w[j]);
                        flag=0;
                    }
                }
            }
            if(flag){
                break;
            }
        }
        cout<<s<<"\n";
        cout<<c<<"\n";
        cout<<"\n";
    }
    return 0;
}