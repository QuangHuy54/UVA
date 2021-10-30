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
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    int n,count,sum=0;
    vii result;
    while(cin>>n){
        count=0;
        for(int i=n+1,k=1;i<=(n*i)/k;i++,k++){
            if((n*i)%k==0){
                result.push_back(make_pair(n*i/k,i));
                count++;
            }
        }
        cout<<count<<"\n";
        for(int i=sum;i<sum+count;i++){
            cout<<"1/"<<n<<" = "<<"1/"<<result[i].first<<" + "<<"1/"<<result[i].second<<"\n";
        }
        sum+=count;
    }
    return 0;
}