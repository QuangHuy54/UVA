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
#include<sstream>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    int n;
    scanf("%d",&n);
    int k;
    int a[5001];
    while(n--){
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d",&a[i]);
        }
        int result=0;
        for(int i=1;i<k;i++){
            for(int j=0;j<i;j++){
                if(a[j]<=a[i]){
                    result++;
                }
            }
        }
        printf("%d\n",result);
    }
    return 0;
}