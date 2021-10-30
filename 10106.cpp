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
int big_len(big a){
    int j;
    for(j=MAX-1;j>=0&&!a[j];j--);
    return j;
}
void big_product(big a,int k){
    int carry=0;
    for(int i=0;i<MAX;i++){
        carry+=k*a[i];
        a[i]=carry%10;
        carry/=10;
    }
}
void big_from_str(big a,string s){
    big_zero(a);
    for(int i=s.size()-1;i>=0;i--){
        a[s.size()-i]=s[i]-'0';
    }
}
string big_to_str(big a){
    ostringstream oss;
    for(int i=big_len(a);i>=0;i--){
        oss<<a[i];
    }
    return oss.str();
}
void big_from_int(big a,int k){
    big_zero(a);
    int temp=0;
    while(k){
        a[temp]=k%10;
        k/=10;
        temp++;
    }
}
void big_add(big a,big b,big result){
    big_zero(result);
    int carry=0;
    for(int i=0;i<MAX;i++){
        result[i]=a[i]+b[i]+carry;
        carry=result[i]/10;
        result[i]%=10;
    }
}
void big_product(big a,big b,big result){
    int lena=big_len(a);
    int lenb=big_len(b);
    int pos=0;
    int carry=0;
    if(lena<lenb){
        big_product(b,a,result);
        return;
    }
    else{
        big_zero(result);
        for(int i=0;i<=lenb;pos=0,carry++,i++){
            for(int j=0;j<=lena;j++,pos++){
                result[pos+carry]+=a[j]*b[i];
                if(result[pos+carry]>=10){
                    result[pos+carry+1]+=result[pos+carry]/10;
                    result[pos+carry]%=10;
                }
            }
        }
    }
}
void big_print(big a){
    for(int i=big_len(a);i>=2;i--){
        cout<<a[i];
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string a,b;
    while(cin>>a){
        cin>>b;
        if(a=="0"||b=="0"){
            cout<<"0"<<"\n";
        }
        else{
        big result;
        big a1;
        big b1;
        big_from_str(a1,a);
        big_from_str(b1,b);
        big_product(a1,b1,result);
        big_print(result);
        }
    }
    return 0;
}