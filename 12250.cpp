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
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t=1;
    while(cin>>s&&s!="#"){
        cout<<"Case "<<t<<": ";
        t++;
        if(s=="HELLO"){
            cout<<"ENGLISH"<<"\n";
        }
        else if(s=="HOLA"){
            cout<<"SPANISH"<<"\n";
        }
        else if(s=="HALLO"){
            cout<<"GERMAN"<<"\n";
        }
        else if(s=="BONJOUR"){
            cout<<"FRENCH"<<"\n";
        }
        else if(s=="CIAO"){
            cout<<"ITALIAN"<<"\n";
        }
        else if(s=="ZDRAVSTVUJTE"){
            cout<<"RUSSIAN"<<"\n";
        }
        else{
            cout<<"UNKNOWN"<<"\n";
        }
    }
    return 0;
}