#include<iostream>
#include<string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    int posM,posE,left,mid,right;
    cin>>t;
    while(t--){
        posM=-1;
        posE=-1;
        bool ok=true;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='M'){
                if(posM==-1){
                posM=i;
                }
                else{
                    ok=false;
                    break;
                }
            }
            else if(s[i]=='E'){
                if(posE==-1){
                posE=i;
                }
                else{
                    ok=false;
                    break;
                }
            }
            else if(s[i]!='?'){
                ok=false;
                break;
            }
        }
        if(posM>posE){
            ok=false;
        }
        if(!ok){
            cout<<"no-theorem"<<"\n";
        }
        else{
            left=posM;
            right=s.size()-posE-1;
            mid=posE-posM-1;
            if(right!=(left+1+(mid-1))||mid==0||left==0||right==0){
                ok=false;
            }
            if(ok){
                cout<<"theorem"<<"\n";
            }
            else{
                cout<<"no-theorem"<<"\n";
            }
        }
    }
    return 0;
}