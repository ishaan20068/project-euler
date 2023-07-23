// first triangular number to have over n divisors
#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;



int numdiv(int n){
    int c=0;
    for (int i=1;i*i<=n;i++){
        if(n%i==0 && i*i!=n){
            c+=2;
        }
        else if(n%i==0 && i*i==n){
            c+=1;
        }
    }
    return c;
}


void ans(){
    int n;
    cin>>n;
    int triangularnumber=1;
    int i=2;
    while(i<LONG_LONG_MAX){
        int div=numdiv(triangularnumber);
        if(div>n){
            o(triangularnumber)
            break;
        }
        triangularnumber+=i;i++;
    }
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
