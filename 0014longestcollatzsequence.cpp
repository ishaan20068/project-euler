#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long

vector<int>dp(1000000,0);
int chainlength(int n){
    if(n==1){return 1;}
    if(n<1000000 && dp[n]!=0){return dp[n];}
    if(n%2==0){return 1+chainlength(n/2);}
    else{return 1+chainlength(3*n+1);}
}

void ans(){
    dp[0]=-1;
    dp[1]=1;
    int maxlen=1,num=1;
    for(int i=2;i<1000000;i++){
        dp[i]=chainlength(i);
        if(dp[i]>maxlen){
            maxlen=max(maxlen,dp[i]);num=i;
        }
    }
    cout<<num<<endl;
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
