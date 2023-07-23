//There exists exactly one Pythagorean triplet for which a + b + c = n. find the product abc.
#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;
#define pb              push_back
bool sq(int n){int x=sqrt(n);return x*x==n;}

vector<int>factorssmall(int n){
    vector<int>ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans.pb(i);
        }
    }
    return ans;
}
// this uses the property that for any pythagorean triplet a^2+b^2=c^2
// there exist integers m,n such that a=m^2-n^2,b=2mn,c=m^2+n^2
// So, a+b+c=2m(m+n)=sumofabc where m>n
// So, the problem is to just find integers m and n such that 2m(m+n)=sumofabc
int findabc2(int sumofabc){
    if(sumofabc%2!=0){
        return -1;
    }
    sumofabc/=2;
    vector<int> smallfactors=factorssmall(sumofabc);
    for(auto f:smallfactors){
        double val=(double)sumofabc/(double)(f*f);
        if(val<2 && val>1){
            int m=f;
            int n=sumofabc/f-f;
            int a=m*m-n*n;
            int b=2*m*n;
            int c=m*m+n*n;
            return a*b*c;
        }
    }
    return -1;
}

//checks if there exist a,b such that a^2+b^2=c^2
//if yes return a*b*c
//else returns -1
int findabc(int sumofabc){
    for(int c=900;c>=1;c--){
        for(int i=1;i<c;i++){
            if(sq(c*c-i*i) && c+i+sqrt(c*c-i*i)==sumofabc){
                return c*(500000-1000*c);
            }
        }
    }
    return -1;
}


// it can be noticed that findabc2 is much faster than findabc
// for example if sumofabc=1000 then 
// Time taken by function findabc: 10788 microseconds
// Time taken by function findabc2: 17 microseconds
void ans(){
    //o(findabc(1000));
    o(findabc2(1000));
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
