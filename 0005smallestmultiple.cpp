// Find the smallest number divisible by all numbers from 1 to n
#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;
int lcm(int a, int b){return (a/__gcd(a,b)*b);}
int power(int a,int b) {if(b==0){return 1;}int res=power(a, b / 2);if (b % 2){return res*res*a;}else{return res*res;}}

// helper function to find the primes up till a number n
vector<int> seive(int n){
    vector<int>primes;
    vector<bool>isprime(n+1,true);
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            for(int j=i*i;j<=n;j+=i){
                isprime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

// this is the first method that uses the seive of eratosthenes to find the primes up till a numher n 
// and then calculates the highest power of every prime in the range 1 to n 
// and multiplies them to get the answer of the smallest number divisible by all numbers from 1 to n
int div(int n){
    vector<int> seives= seive(n);
    int ans=1;
    for(int i=0;i<seives.size();i++){
        int p=seives[i];
        ans=ans*power(p,floor(log(n)/log(p)));
    }
    return ans;
}

// helper function to find the lcm of a vector of numbers
int findlcm(vector<int> v){
    int ans=1;
    if(v.size()<1){return 0;}
    if(v.size()==1){return v[0];}
    if(v.size()==2){return lcm(v[0],v[1]);}
    else{
        vector<int> v1;
        if(v.size()%2==0){
            for(int i=0;i<v.size();i+=2){
                v1.push_back(lcm(v[i],v[i+1]));
            }
        }
        else{
            for(int i=0;i<v.size()-1;i+=2){
                v1.push_back(lcm(v[i],v[i+1]));
            }
            v1.push_back(v[v.size()-1]);
        }
        return findlcm(v1);
    }
}

// this is the second method that uses a divide and conquer approach to find the lcm of all numbers from 1 to n
// it uses the helper function findlcm to find the lcm of a vector of numbers
// it can be noted that this function is much faster than the first method in expectation
int div2(int n){
    vector<int> v;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    return findlcm(v);
}


void ans(){
    int n;
    cin>>n;
    //o(div(n))
    o(div2(n))
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
