// given n find sum of digits of 2^n
#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define o(x)            cout<<x<<endl;
typedef vector<string>                  vs;
//  a function to add two strings
string add(string a,string b){
    int n,m;
    if(a.size()>b.size()){n=a.size();m=b.size();}
    else{n=b.size();m=a.size();swap(a,b);}
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int carry=0;
    string ans="";
    for(int i=0;i<m;i++){
        int x=(a[i]-'0')+(b[i]-'0')+carry;
        ans+=('0'+x%10);
        carry=x/10;
    }
    for(int i=m;i<n;i++){
        int x=(a[i]-'0')+carry;
        ans+=('0'+x%10);
        carry=x/10;
    }
    if(carry){
        ans+=('0'+carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string addstr(vector<string> x){
    string ans="0";
    for(auto i:x){
        ans=add(ans,i);
    }
    return ans;
}
// a function to multiply a string with a char
string mul(string a,char b){
    string ans="";
    int carry=0;
    for(int i=a.size()-1;i>=0;i--){
        int x=(a[i]-'0')*(b-'0')+carry;
        ans+=('0'+x%10);
        carry=x/10;
    }
    if(carry){
        ans+=('0'+carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
// a function to multiply two strings
string stringmultiply(string a,string b){
    vector<string> v;string val="";
    reverse(b.begin(),b.end());
    for(auto i:b){
        v.push_back(mul(a,i)+val);
        val+="0";
    }
    return addstr(v);
}
// a dp array to store the values of 2^n=dp[n]
vs dp;
// a function to calculate 2^n
string twopow(int n){
    if(n==0){return "1";}
    if(n==1){return "2";}
    if(dp[n]!=""){return dp[n];}
    string ans="";
    if(n%2==0){
        string x=twopow(n/2);
        ans=stringmultiply(x,x);
    }
    else{
        string x=twopow(n/2);
        ans=stringmultiply(x,x);
        ans=stringmultiply(ans,"2");
    }
    dp[n]=ans;
    return ans;
}

void ans(){
    int n;
    cin>>n;
    dp=vs(n+1,"");
    string ans=twopow(n);
    int sum=0;
    for(auto i:ans){
        sum+=(i-'0');
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
