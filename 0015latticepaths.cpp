//given an nxn grid and that you can move only right and downn, find the total number 
// of ways to reach the bottom right corner from the top left corner
#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;


// note that the total number of moves needed to do this are 2n
// So it suffices to choose the n moves out of the 2n moves that are down moves
// So the answer is C(2n,n)

void ans(){
    int n;
    cin>>n;
    double x=1.0;
    for(int i=0;i<n;i++){
        x*=(double)(2*n-i)/(double)(i+1);
    }
    o((int)x)
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
