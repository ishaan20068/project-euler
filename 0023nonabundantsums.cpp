#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;
typedef unordered_map<int,int>          umll;

//let us call the numbers that can be written as the sum of two abundant numbers as good numbers
umll isabundant;
umll isgood;
// this functionchecks whether a number is abundant or not
// it also updates the isabundant map
void abundant(int n){
    int sum=0;bool isab=false;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i){
                sum+=i;
            }
            else{
                if(i==1){sum-=n;}
                sum+=i;
                sum+=(n/i);
            }
        }
        if(sum>n){isab=true;break;}
    }
    if(isab){isabundant[n]=1;}
}



void ans(){
    int n=28123;
    for(int i=1;i<=n;i++){
        abundant(i);
    }
    for(auto i:isabundant){
        for(auto j:isabundant){
            if(i.first+j.first<=n){
                isgood[i.first+j.first]=1;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(isgood[i]!=1){
            sum+=i;
        }
    }
    o(sum)
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
