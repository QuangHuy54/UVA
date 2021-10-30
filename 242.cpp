#include<iostream>
#include<climits>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;
int compare(vector<int> a,vector<int> b){
    if(a.size()<b.size()){
        return -1;
    }
    else if(a.size()==b.size()){
        for(int i=a.size()-1;i>=0;i--){
            if(a[i]<b[i]){
                return -1;
            }
            else if(a[i]>b[i]){
                return 1;
            }
        }
        return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s,n,f,x;
    while(cin>>s&&s){
        cin>>f;
        int res=0;
        vector<int> ans;
        bool first=1;
        while(f--){
            cin>>n;
            vector<int> a;
            for(int i=0;i<n;i++){
                cin>>x;
                a.push_back(x);
            }
            int temp=0;
            int dp[1004];
            memset(dp,0,sizeof(dp));
            dp[0]=1;
            for(int i=0;i<n;i++){
                for(int k=0;k<=1000;k++){
                    if(dp[k]&&dp[k]<=s){
                        if(dp[k+a[i]]>dp[k]+1||dp[k+a[i]]==0){
                            dp[k+a[i]]=dp[k]+1;
                        }
                    }
                }
            }
            while(dp[temp]){
                temp++;
            }
            temp--;
            if(first){
                first=false;
                res=temp;
                ans.clear();
                ans=a;
            }
            else if(res<temp){
                res=temp;
                ans.clear();
                ans=a;
            }
            else if(res==temp&&compare(a,ans)==-1){
                ans.clear();
                ans=a;
            }
        }
        cout<<"max coverage ="<<setw(4)<<res;
        cout<<" :";
        for(int i=0;i<ans.size();i++){
            cout<<setw(3)<<ans[i];
        }
        cout<<"\n";
    }
}