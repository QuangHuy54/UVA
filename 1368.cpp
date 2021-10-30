#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,len,index,ans;
    string a[51],res;
    int dat[27];
    cin>>t;
    while(t--){
        cin>>n>>len;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        res="";
        ans=0;
        for(int i=0;i<len;i++){
            memset(dat,0,sizeof(dat));
            index=0;
            for(int j=0;j<n;j++){
                dat[a[j][i]-'A']++;
                if(dat[a[j][i]-'A']>dat[index]){
                    index=a[j][i]-'A';
                }
                else if(dat[a[j][i]-'A']==dat[index]){
                    index=min(index,a[j][i]-'A');
                }
            }
            for(int i=0;i<26;i++){
                if(i!=index){
                    ans+=dat[i];
                }
            }
            res+=(index+'A');
        }
        cout<<res<<"\n"<<ans<<"\n";
    }
    return 0;
}