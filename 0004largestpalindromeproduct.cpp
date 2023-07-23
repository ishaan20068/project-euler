// largest palindrome that can be formed by the product of two n digit numbers
#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;
int power(int a,int b) {if(b==0){return 1;}int res=power(a, b / 2);if (b % 2){return res*res*a;}else{return res*res;}}

bool pal(int n){
    int dummy=n;
    int rev=0;
    while(n>0){
        int d=n%10;
        rev=rev*10+d;
        n=n/10;
    }
    if(rev==dummy){return true;}
    return false;
}


//note that the largest palindrome that can be formed by the product of two n digit numbers needs to have 2n digits
//because 9...n times..9^2=9..(n-1 times)80..(n-1 times)..01 which is exactly 2n digits
// so the product of twp n digit numbers can never cross 2n digits
int palgen(int n){
    int x=power(10,n)-1;
    int y=power(10,n-1);
    for(int i=x;i>=9*y;i--){
        for(int j=x;j>=9*y;j--){
            int p=i*j;
            if(pal(p)){return p;}
        }
    }
    for(int i=9*y;i>=8*y;i--){
        for(int j=9*y;j>=8*y;j--){
            int p=i*j;
            if(pal(p)){return p;}
        }
    }
    for(int i=8*y;i>=7*y;i--){
        for(int j=8*y;j>=7*y;j--){
            int p=i*j;
            if(pal(p)){return p;}
        }
    }
    for(int i=7*y;i>=6*y;i--){
        for(int j=7*y;j>=6*y;j--){
            int p=i*j;
            if(pal(p)){return p;}
        }
    }
    for(int i=6*y;i>=5*y;i--){
        for(int j=6*y;j>=5*y;j--){
            int p=i*j;
            if(pal(p)){return p;}
        }
    }
    for(int i=5*y;i>=4*y;i--){
        for(int j=5*y;j>=4*y;j--){
            int p=i*j;
            if(pal(p)){return p;}
        }
    }
    for(int i=4*y;i>=3*y;i--){
        for(int j=4*y;j>=3*y;j--){
            int p=i*j;
            if(pal(p)){return p;}
        }
    }
    for(int i=3*y;i>=2*y;i--){
        for(int j=3*y;j>=2*y;j--){
            int p=i*j;
            if(pal(p)){return p;}
        }
    }
    for(int i=2*y;i>=y;i--){
        for(int j=2*y;j>=y;j--){
            int p=i*j;
            if(pal(p)){return p;}
        }
    }
    return -1;
}

void ans(){
    int n;
    cin>>n;
    o(palgen(n))
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
