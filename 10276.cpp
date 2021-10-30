#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int i,j,t,n=1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        int f[51],temp;
        memset(f,0,sizeof(f));
        f[0]=1;
        for(i=2;;i++){
            for(j=0;j<n;j++){
                temp=(int)sqrt(f[j]+i);
                if(temp*temp==f[j]+i||f[j]==0){
                    f[j]=i;
                    break;
                }
            }
            if(j==n){
                break;
            }
        }
        cout<<i-1<<"\n";
    }
    return 0;
}