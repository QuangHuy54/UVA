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
struct people{
    string name;
    int day;
    int month;
    int year;
};
bool compare(people a,people b){
    if(a.year!=b.year){
        return a.year<b.year;
    }
    else{
        if(a.month!=b.month){
            return a.month<b.month;
        }
        else{
            return a.day<b.day;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    string s;
    people a[101];
    for(int i=0;i<n;i++){
        cin>>a[i].name>>a[i].day>>a[i].month>>a[i].year;
    }
    sort(a,a+n,compare);
    cout<<a[n-1].name<<"\n";
    cout<<a[0].name<<"\n";
}