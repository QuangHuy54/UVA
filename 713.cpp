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
#define all(v) ((v).begin()),((v).end())
#define sz(v)  ((int)((v).size()))
#define clr(v, d) memset(v,d,sizeof(v))
const int MAX=300;
typedef int big[MAX];
void big_zero(big a){
    for(int i=0;i<MAX;i++){
        a[i]=0;
    }
}
void big_from_str(string s,big a){
    big_zero(a);
    int len=s.size()-1;
    for(int i=0;i<=len;i++){
        a[i]=s[i]-'0';
    }
}
void big_add(big a,big b,big result){
    big_zero(result);
    int carry=0;
    for(int i=0;i<MAX;i++){
        result[i]=carry+a[i]+b[i];
        carry=result[i]/10;
        result[i]%=10;
    }
}
int big_len(big a){
    int j;
    for(j=MAX-1;j&&!a[j];j--);
    return j;
}
string big_to_str(big a){
    ostringstream oss;
    for(int i=0;i<=big_len(a);i++){
        oss<<a[i];
    }
    string result=oss.str();
    int k=0;
    for(int i=0;i<result.size();i++){
        if(result[i]=='0'){
            k++;
        }
        else{
            break;
        }
    }
    result.erase(0,k);
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string a,b;
    while(n--){
        cin>>a>>b;
        big a1,b1,result1;
        big_from_str(a,a1);
        big_from_str(b,b1);
        big_add(a1,b1,result1);
        string result=big_to_str(result1);
        cout<<result<<"\n";
    }
    return 0;
}