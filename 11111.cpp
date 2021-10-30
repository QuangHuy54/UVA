#include<iostream>
#include<stack>
#include<sstream>
using namespace std;
int a[10000005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        int k,n=0;
        stack<int> st;
        stack<int> sum;
        while(ss>>k){
            a[n++]=k;
        }
        if(n%2!=0){
            cout<<":-( Try again."<<"\n";
        }
        else{
            bool solve=true;
            for(int i=0;i<n;i++){
                if(a[i]<0){
                    if(st.empty()){
                        st.push(abs(a[i]));
                        sum.push(abs(a[i]));
                    }
                    else{
                        if(sum.top()<=abs(a[i])){
                            solve=false;
                            break;
                        }
                        int temp=sum.top();
                        temp-=abs(a[i]);
                        sum.pop();
                        sum.push(temp);
                        st.push(abs(a[i]));
                        sum.push(abs(a[i]));
                    }
                }
                else{
                    if(st.empty()){
                        solve=false;
                        break;
                    }
                    if(a[i]!=st.top()){
                        solve=false;
                        break;
                    }
                    st.pop();
                    sum.pop();
                }
            }
            if(!st.empty()){
                solve=false;
            }
            if(solve){
                cout<<":-) Matrioshka!"<<"\n";
            }
            else{
                cout<<":-( Try again."<<"\n";
            }
        }
    }
    return 0;
}