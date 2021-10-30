#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	string s;
	long long a[35];
	for(int i=1;i<=32;i++){
	    a[i]=pow(2,i)-1;
	}
	int res;
	while(cin>>s&&s!="0"){
	    res=0;
	    int len=s.size();
	    for(int i=len-1;i>=0;i--){
	        res+=a[len-i]*(s[i]-'0');
	    }
	    cout<<res<<"\n";
	}
	return 0;
}