#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<unordered_map>
#include<sstream>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
using namespace std;
int main(){
    int n;
    string name[1009];
    while(cin>>n&&n!=0){
        for(int i=0;i<n;i++){
            cin>>name[i];
        }
        sort(name,name+n);
        string result="";
        string a=name[(n/2)-1];
        string b=name[n/2];
        for(int i=0;i<a.size();i++){
            if(i==a.size()-1){
                result=a;
                break;
            }
            if(a[i]=='Z'){
                result+=a[i];
            }
            else if(i>=b.size()){
                result+=a[i]+1;
                break;
            }
            else{
            if(a[i]==b[i]){
                result+=a[i];
            }
            else{
                if(b[i]>a[i]+1){
                    result+=a[i]+1;
                    break;
                }
                else{
                    if(i<b.size()-1){
                        result+=a[i]+1;
                        break;
                    }
                    else{
                        result+=a[i];
                    }
                }
            }
            }
        }
        cout<<result<<"\n";
    }
    return 0;
}