#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int comb[1001],perm[1001];
set<vector<int>> s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> a;
    int first=1;
    for(int i=0;i<=20;i++){
        a.insert(i);
        a.insert(2*i);
        a.insert(3*i);
    }
    a.insert(50);
    vector<int> value;
    int n,sum,t;
    for(auto i=a.begin();i!=a.end();i++){
        value.push_back(*i);
    }
    for(int i=0;i<value.size();i++){
        for(int j=0;j<value.size();j++){
            for(int k=0;k<value.size();k++){
                vector<int> temp={value[i],value[j],value[k]};
                if(s.find(temp)==s.end()){
                    sort(temp.begin(),temp.end());
                    comb[value[i]+value[j]+value[k]]++;
                    t=0;
                    do{
                        t++;
                        s.insert(temp);
                    }while(next_permutation(temp.begin(),temp.end()));
                    perm[value[i]+value[j]+value[k]]+=t;
                }
            }
        }
    }
    while(cin>>n){
        if(first){
            first=0;
        }
        else{
            cout<<"**********************************************************************"<<"\n";
        }
        if(n<=0){
            cout<<"END OF OUTPUT"<<"\n";
            break;
        }
        if(comb[n]==0){
            cout<<"THE SCORE OF "<<n<<" CANNOT BE MADE WITH THREE DARTS."<<"\n";
        }
        else{
            cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<n<<" IS "<<comb[n]<<"."<<"\n";
            cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<n<<" IS "<<perm[n]<<"."<<"\n";
        }
    }
}