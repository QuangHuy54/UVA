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
struct Contest{
    int number;
    int solve;
    int penalty;
};
bool compare(Contest a,Contest b){
    if(a.solve==b.solve){
        if(a.penalty==b.penalty){
            return a.number<b.number;
        }
        else return a.penalty<b.penalty;
    }
    else{
        return a.solve>b.solve;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int ids,problem,times;
    string s;
    getline(cin, s);
    getline(cin, s);
    char c;
    bool id[105],solved[105][11];
    int store[105],time[105],numberpro[105],error[105][11];
    while(n--){
        int cnt=0;
        memset(id,false,sizeof(id));
        memset(solved,false,sizeof(solved));
        memset(store,0,sizeof(store));
        memset(time,0,sizeof(time));
        memset(numberpro,0,sizeof(numberpro));
         memset(error,0,sizeof(error));
        while(getline(cin,s)&&s!=""){
            stringstream ss(s);
	        ss >> ids >> problem >> times >> c;
            if(!id[ids]){
                id[ids]=true;
                store[cnt]=ids;
                cnt++;
            }
            if(c=='R'||c=='U'||c=='E'){continue;}
            if(c=='C'&&!solved[ids][problem]){
                numberpro[ids]++;
                solved[ids][problem]=true;
                time[ids]=time[ids]+times+error[ids][problem];
            }
            else if(c=='I'&&!solved[ids][problem]){
                error[ids][problem]+=20;
            }
        }
        Contest data[105];
        for(int i=0;i<cnt;i++){
            if(id[store[i]]){
                data[i].number=store[i];
                data[i].solve=numberpro[store[i]];
                data[i].penalty=time[store[i]];
            }
        }
        sort(data,data+cnt,compare);
        for(int i=0;i<cnt;i++){
            cout<<data[i].number<<" "<<data[i].solve<<" "<<data[i].penalty<<"\n";
        }
        if(n){
            cout<<"\n";
        }
    }
    return 0;
}