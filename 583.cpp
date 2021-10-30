#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> prime;
    bool ok[46340];
    memset(ok,1,sizeof(ok));
    for(int i=2;i<=46340;++i){
        if(ok[i]){
            prime.push_back(i);
            for(int j=i*i;j<=46340;j+=i){
                ok[j]=false;
            }
        }
    }
    long long n;
    while(cin>>n&&n){
        cout<<n<<" = ";
        bool flag=false;
        if(n<0){
            cout<<"-1 x ";
            n*=-1;
        }
        if(n==1){
            cout<<"\n";
        }
        else{
            int k=0;
            while(n!=1&&k<prime.size()){
                if(prime[k]!=0){
                if((n%prime[k])==0){
                    if((n/prime[k])!=1){
                        cout<<prime[k]<<" x ";
                        flag=true;
                    }
                    else{
                        cout<<prime[k]<<"\n";
                    }
                    n/=prime[k];
                }
                else{
                    k++;
                }
                }
            }
            if(n>1){
                if(flag){
                    cout<<" x "<<n<<"\n";
                }
                else{
                    cout<<n<<"\n";
                }
            }
        }
    }
    return 0;
}