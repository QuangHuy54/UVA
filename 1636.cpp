#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(cin>>s){
        int numOne=0;
        int numZero=0;
        int nextOne=0;
        int nextZero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                numZero++;
                if(i==s.size()-1){
                    if(s[0]=='0'){
                        nextZero++;
                    }
                    else{
                        nextOne++;
                    }
                }
                else{
                    if(s[i+1]=='0'){
                        nextZero++;
                    }
                    else{
                        nextOne++;
                    }
                }
            }
            else{
                numOne++;
            }
        }
        double res1=(double)nextZero/(nextZero+nextOne);
        double res2=(double)numZero/(numZero+numOne);
        if(res1==res2){
            cout<<"EQUAL"<<"\n";
        }
        else if(res1>res2){
            cout<<"SHOOT"<<"\n";
        }
        else{
            cout<<"ROTATE"<<"\n";
        }
    }
}