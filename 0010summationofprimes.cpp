#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;

// Using the seive approach to find the sum of primes upto n

int primesum(int n){
    if(n<2){return 0;}
    int sum=2;
    vector<bool>isprime(1000000,true);
    for(int i=0;i<1000000;i++){
        if(isprime[i]){
            int number=2*i+3;
            sum+=number; 
            for(int j=number*number;j<2000000;j+=2*number){
                isprime[(j-3)/2]=false;
            }
        }
        if(2*i+3==n || 2*i+3==n-1){
            return sum;
        }
    }

    return sum;
}


void ans(){
    int n;
    cin>>n;
    o(primesum(n))
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
