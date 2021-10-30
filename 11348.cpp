#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<iomanip>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> a[52];
    int unique[52];
    int k,n,m,x,sum,c=0;
    map<int,int> collection;
    cin>>k;
    while(k--){
        cin>>n;
        for(int i=0;i<n;i++){
            a[i].clear();
        }
        sum=0;
        collection.clear();
        for(int i=0;i<n;i++){
            cin>>m;
            for(int j=0;j<m;j++){
                cin>>x;
                a[i].insert(x);
            }
        }
        for(int i=0;i<n;i++){
            for(auto j=a[i].begin();j!=a[i].end();j++){
                if(collection.find(*j)==collection.end()){
                    collection[*j]=1;
                }
                else{
                    collection[*j]++;
                }
            }
        }
        memset(unique,0,sizeof(unique));
        for(int i=0;i<n;i++){
            for(auto j=a[i].begin();j!=a[i].end();j++){
                if(collection[*j]==1){
                    unique[i]++;
                    sum+=1;
                }
            }
        }
        cout<<"Case "<<++c<<":";
        for(int i=0;i<n;i++){
            double temp;
            if(sum==0){
                temp=0.0;
            }
            else{
                temp=(unique[i]*100.0)/sum;
            }
            cout<<" "<<fixed<<temp<<"%";
        }
        cout<<"\n";
    }
    return 0;
}