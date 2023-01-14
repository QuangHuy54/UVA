#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include <stack>
#include <queue>
#include <climits>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
ll a[10][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        for(int i=1;i<=9;i+=2){
            for(int j=1;j<=i;j+=2){
                cin>>a[i][j];
            }
        }
        for(int i=3;i<=9;i+=2){
            for(int j=2;j<=i;j+=2){
                a[i][j]=(a[i-2][j-1]-a[i][j-1]-a[i][j+1])/2;
                a[i-1][j-1]=a[i][j-1]+a[i][j];
                a[i-1][j]=a[i][j]+a[i][j+1];
            }
        }
        for(int i=1;i<=9;i++){
            for(int j=1;j<=i;j++){
                if(j!=1){
                    cout<<" ";
                }
                cout<<a[i][j];
            }
            cout<<"\n";
        }

    }
    return 0;
}