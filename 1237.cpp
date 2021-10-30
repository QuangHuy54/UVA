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
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k,count=0,queries,queri=0,c=1;
    string result="";
    vector<string> M(10000);
    vi L(10000);
    vi H(10000);
    cin>>t;
    while(t--){
        if(c>1){
            cout<<"\n";
        }
        count=0;
        cin>>n;
        while(n--){
            cin>>M[count]>>L[count]>>H[count];
            count++;
        }
        cin>>k;
        while(k--){
            cin>>queries;
            queri=0;
            result="";
            for(int i=0;i<count;i++){
                if(queries>=L[i]&&queries<=H[i]){
                    queri++;
                    result=M[i];
                }
            }
            if(queri==1){
                cout<<result<<"\n";
            }
            else{
                cout<<"UNDETERMINED"<<"\n";
            }
        }
        c++;
    }
    return 0;
}