#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define fr(i,n)         for(int i=0;i<n;i++)
#define o(x)            cout<<x<<endl;




void ans(){
    int n;
    cin>>n;
    int a[n][n];
    fr(i,n){
        fr(j,n){
            cin>>a[i][j];
        }
    }
    //horizontal checking
    int maxprod=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-3;j++){
            int p=a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
            maxprod=max(maxprod,p);
        }
    }
    //vertical checking
    for(int i=0;i<n-3;i++){
        for(int j=0;j<n;j++){
            int p=a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
            maxprod=max(maxprod,p);
        }
    }
    //diagonal checking topleft to bottomright
    for(int i=0;i<n-3;i++){
        for(int j=0;j<n-3;j++){
            int p=a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
            maxprod=max(maxprod,p);
        }
    }
    //diagonal checking topright to bottomleft
    for(int i=0;i<n-3;i++){
        for(int j=3;j<n;j++){
            int p=a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
            maxprod=max(maxprod,p);
        }
    }
    o(maxprod)
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
