#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    int special[22]={1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
47045881, 64000000,85766121};
    while(cin>>x&&x){
        //if(x==1||x==64||x==729||x==4096||x==15625||x==46656||x==117649||x==262144||x==531441||x==1000000||x==1771561||2985984||x==4826809||x==7529536||x==11390625||x==16777216||x==24137569||x==34012224||x==47045881||x==64000000||x==85766121){
        if(binary_search(special,special+21,x)){
            cout<<"Special"<<"\n";
        }
        else{
            cout<<"Ordinary"<<"\n";
        }
    }
    return 0;
}