#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;


int nthprime(int n){
    vector<int>primes={2};
    vector<bool>isprime(1000000,true);
    for(int i=0;i<1000000;i++){
        if(isprime[i]){
            int number=2*i+3;
            primes.push_back(number);
            for(int j=number*number;j<=2000001;j+=2*number){
                isprime[(j-3)/2]=false;
            }
        }
        if(primes.size()>=n){
            return primes[n-1];
        }
    }
    return -1;
}




void ans(){
    int n;
    cin>>n;
    o(nthprime(n))
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
