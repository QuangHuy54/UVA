#include<bits/stdc++.h>
using namespace std;
void reconstruct_print(int end, int a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("[%d", a[x]);
  for (; !s.empty(); s.pop()) printf(", %d", s.top());
  printf("]\n");
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int answ[200002];
    int prev[200002];
    int id[200002];
    int lis=0,lis_end=0;
    vector<int> ar;
    int x;
    while(cin>>x){
        ar.push_back(x);
    }
    for(int i=0;i<ar.size();i++){
        int pos=lower_bound(answ,answ+lis,ar[i])-answ;
        answ[pos]=ar[i];
        id[pos]=i;
        if(pos>0){
            prev[i]=id[pos-1];
        }
        else{
            prev[i]=-1;
        }
        if(pos==lis){
            ++lis;
            lis_end=i;
        }
    }
    vector<int> res;
    int k=lis_end;
    for(;prev[k]>=0;k=prev[k]){
        res.push_back(ar[k]);
    }
    reverse(res.begin(),res.end());
    cout<<lis<<"\n";
    cout<<"-"<<"\n";
    cout<<ar[k]<<"\n";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"\n";
    }
    return 0;
}