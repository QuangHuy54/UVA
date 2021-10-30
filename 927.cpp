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
    long long n;
    int ar[21];
    int c,a,x,d,k;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&a);
        for(int i=0;i<=a;i++){
            scanf("%d",&ar[i]);
        }
        scanf("%d %d",&d,&k);
        int i=1;
        int s=i*d;
        while(s<k){
            i++;
            s+=i*d;
        }
        n=0;
        for(int j=0;j<=a;j++){
            n+=ar[j]*(long long)pow(i,j);
        }
        printf("%lld\n",n);
    }
    return 0;
}