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
#include<string.h>
#include<string>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    char check;
    long long S;
    vector<int> array(255);
    string s;
    double result;
    cin>>n;
    while(n--){
        result=0;
        S=0;
        cin>>m;
        while(m--){
            cin>>check;
            cin>>array[check];
        }
        cin>>k;
        cin.ignore();
        while(k--){
            s="";
            getline(cin,s);
            for(int i=0;i<s.length();i++){
                S+=array[s[i]];
            }
        }
        result=(double)S/100;
        printf("%0.2lf$\n",result);
        fill(array.begin(),array.end(),0);
    }
    return 0;
}