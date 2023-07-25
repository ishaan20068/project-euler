#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void ans(){
    int n;
    cin>>n;
    //according to the binet's formula the nth fibonacci number is given by
    //F(k)=((alpha)^k-(beta)^k)/sqrt(5)
    // where alpha=(1+sqrt(5))/2 and beta=(1-sqrt(5))/2
    // we have to find the first fibonacci number with 1000 digits
    // we can find the number of digits in a number by using the formula floor(log10(t))+1
    // Now, for large k, the value of beta^k is very small and can be neglected
    //so, the kth fibonacci number is approximately equal to (alpha)^k/sqrt(5)
    // the number of digits in (alpha)^k/sqrt(5) is given by floor(log10(alpha^k/sqrt(5)))+1=n
    // => log10(alpha^k/sqrt(5))=n-1  =>  alpha^k/sqrt(5)=10^(n-1) => k*log10(alpha)-log10(sqrt(5))=n-1
    // => k*log10(alpha)=n-1+log10(sqrt(5))  =>  k=(n-1+log10(sqrt(5)))/log10(alpha))
    double alpha=(1+sqrt(5))/2;
    cout<<ceil((n-1+log10(sqrt(5)))/log10(alpha))<<endl;
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
