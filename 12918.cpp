#include <iostream>
using namespace std;
 
int main() {
	int n,m,t;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    cout<<n*(m-n)+((n-1)*n)/2<<"\n";
	}
	return 0;
}