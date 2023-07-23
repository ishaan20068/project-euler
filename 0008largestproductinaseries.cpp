#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;

void ans(){
    string n;cin>>n;int prod=1;
    for(int i=0;i<n.size()-12;i++){
        string s=n.substr(i,13);
        int p=1;
        for(int j=0;j<13;j++){
            p*=s[j]-'0';
        }
        prod=max(prod,p);
    }
    o(prod)
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
