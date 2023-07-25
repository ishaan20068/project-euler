#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define o(x)            cout<<x<<endl;



void ans(){
    int n=1000000;
    //now for the millionth permutation we can subtract 9! twice from it and put the starting digit as 2
    // then we can subtract 8! from it and put the second digit as 1
    // From there we can use computation to find the permutations of the digits 1,3,4,5,6,7,8,9

    int fact9=362880;
    int fact8=40320;
    n-=2*fact9;
    n-=fact8;
    int a[10]={2,1,0,3,4,5,6,7,8,9};
    for(int i=0;i<n-1;i++){
        next_permutation(a,a+10);
    }
    string s="";
    for(auto i:a){
        s+=('0'+i);
    }
    o(s)
}

int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
