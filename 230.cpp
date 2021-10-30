#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<map>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
typedef struct{
    string name,author;
}book;
bool compare(book a,book b){
    if(a.author!=b.author){
        return a.author<b.author;
    }
    else{
        return a.name<b.name;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<book> list;
    string input;
    book currentbook;
    while(getline(cin,input)){

    }
    return 0;
}