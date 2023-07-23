//given a number find its largest prime factor
#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             unsigned long long
#define o(x)            cout<<x<<endl;
#define pb              push_back


// normal factor checking - O(sqrt(n))
// start from d=2, the maximum factor found till now is 2
// check if d divides n if yes then remove completely the factor d from n by continuously dividing by d 
// and set maximum factor to d
// note that this way the the maximum factor value will always hold a prime number 
// because other wise if d=kl then k and l must have been removed completely from the number before d
// which is a contradiction, so, d is always prime
// now we keep increasing d and checking divisibility for all d
// Now, any number n can have atmost one prime factor greater than sqrt(n)
// because if it has two prime factors greater than sqrt(n) then their product will be greater than n
// so, if we reach d=sqrt(n) or d*d>n and n is still greater than 1 then n must be a prime number greater than maxfac
// so in this case we return n
// else we return maxfac
int sqrtn(int n){
    int d=2;int maxfac=1,dummy=n;
    while(n>1){
        if(n%d==0){
            maxfac=max(maxfac,d);
            while(n%d==0){n=n/d;}
        }
        if(dummy<d*d){break;}
        d++;
    }
    if(n>1){return n;}
    return maxfac;
}


// this function checks whether the number has 2 odd factors which have a pretty small difference
// if yes then it returns both the factors else it returns {0,0}
// if the number is even then it can be first converted to odd as we can repeatedly divide by 2
// so, we can check for odd numbers only
// now, if the number is odd then we can check for factors that are all odd, which mean their difference is even
// so, we can check for factors that are of the form (x+y) and (x-y)
// Their difference is 2y which is even and n=x^2-y^2
// so, y=sqrt(x^2-n) and x=sqrt(n+y^2)
// so, we can check for a certain number of y and see if x is an integer or not
// if yes then we return {x,y} else we return {0,0}
vector<int> fermat(int n){
    vector<int>ans;
    int f1=1,f2=1;
    if(n%2==0){while(n%2==0){n=n/2;}}
    for(int y=0;y<100;y++){
        int x=sqrt(n+y*y);
        if(x*x==n+y*y){
            f1=x+y;
            f2=x-y;
            ans.pb(f1);
            ans.pb(f2);
            return ans;
        }
    }
    ans.pb(0);
    ans.pb(0);
    return ans;
}

// this function finds the maximum prime factor of a number
// it recursively finds the maximum prime factor of the two factors of the number
// It performs better in expectation than the normal method
// for example when n=600851475143, largest prime factor is 6857
//Time taken by normal method: 132 microseconds
//Time taken by fermat method: 17 microseconds
//Time taken by hybrid method: 87 microseconds
//The results show that this method is faster than the sqrtn method
// in case the number is a large prime number then the sqrtn method is faster
int findmaxprimefactor(int n){
    vector<int>ans=fermat(n);
    if(ans[0]==0 && ans[1]==0){return sqrtn(n);}
    else{return max(findmaxprimefactor(ans[0]),findmaxprimefactor(ans[1]));}
}

void ans(){
    int n;
    cin>>n;
    o(findmaxprimefactor(n))
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
