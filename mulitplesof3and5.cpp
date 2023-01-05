/*If we list all the natural numbers below 10 that are 
multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of 
these multiples is 23. Find the sum of all the multiples
of 3 or 5 below 1000. In general for any two integers a
and b, find the sum of all multiples of a or b less than n*/
#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
int lcm(int a, int b){return (a/gcd(a,b)*b);}

void ans(){
    int a,b,n;
    cin>>a>>b>>n;
    int sum=0;
    sum+=(floor(n/a)*(a*(floor(n/a)+1)))/2;
    sum-=(floor(n/lcm(a,b))*(lcm(a,b)*(floor(n/lcm(a,b))+1)))/2;
    sum+=(floor(n/b)*(b*(floor(n/b)+1)))/2;
    if(n%a==0 || n%b==0){sum-=n;}
    o(sum)
}
int32_t main(){
    fast
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
