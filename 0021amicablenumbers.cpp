// find all amicable numbers less than n
#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;

bool isamicable(int n){
    int sum=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i){sum+=i;}
            else{sum+=i;sum+=n/i;}
        }
    }
    sum-=n;
    int sum2=0;
    for(int i=1;i<=sqrt(sum);i++){
        if(sum%i==0){
            if(sum/i==i){sum2+=i;}
            else{sum2+=i;sum2+=sum/i;}
        }
    }
    sum2-=sum;
    return sum2==n && sum!=n;
}

void ans(){
    int n;
    cin>>n;int sum=0;
    for(int i=1;i<n;i++){
        if(isamicable(i)){sum+=i;}
    }
    o(sum)
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
