#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n,k,m,common[24],tower[24],t=0,c,value[12],temp,res,sum,temp1,best;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>k&&(n||k)){
        for(int i=0;i<n;++i){
            cin>>tower[i];
        }
        cin>>m;
        memset(common,0,sizeof(common));
        for(int v=0;v<m;v++){
            cin>>c;
            for(int i=1;i<=c;++i){
                cin>>temp;
                common[v]|=(1<<(--temp));
            }
            cin>>value[v];
        }
        res=0;
        for(int i=0;i<(1<<n);++i){
            if(__builtin_popcount(i)==k){
                sum=0;
                for(int j=0;j<n;++j){
                    if(i&(1<<j)){
                        sum+=tower[j];
                    }
                }
                for(int j=0;j<m;++j){
                    if(i&common[j]){
                        temp1=__builtin_popcount(i&common[j]);
                        sum-=(temp1-1)*value[j];
                    }
                }
                if(sum>res){
                    res=sum;
                    best=i;
                }
            }
        }
        cout<<"Case Number  "<<++t<<"\n";
        cout<<"Number of Customers: "<<res<<"\n";
        cout<<"Locations recommended:";
        for(int j=0;j<n;++j){
            if(best&(1<<j)){
                cout<<" "<<j+1;
            }
        }
        cout<<"\n";
        cout<<"\n";
    }
    return 0;
}