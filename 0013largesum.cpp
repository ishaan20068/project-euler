#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long



// function to add two numbers in string form
string addstring(string a,string b){
    int n=a.size();
    int m=b.size();
    if(n<m){
        swap(a,b);
        swap(n,m);
    }
    int carry=0;
    string ans="";
    for(int i=0;i<m;i++){
        int sum=(a[n-i-1]-'0')+(b[m-i-1]-'0')+carry;
        ans+=to_string(sum%10);
        carry=sum/10;
    }
    for(int i=m;i<n;i++){
        int sum=(a[n-i-1]-'0')+carry;
        ans+=to_string(sum%10);
        carry=sum/10;
    }
    if(carry){
        ans+=to_string(carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// function to add all the strings in an array one by one
string sum(string a[],int n){
    string ans="0";
    for(int i=0;i<n;i++){
        ans=addstring(ans,a[i]);
    }
    return ans;
}

//function to add all the strings in an array using divide and conquer
string sum2(string a[],int n){
    if(n==1){
        return a[0];
    }
    if(n==2){
        return addstring(a[0],a[1]);
    }
    int mid=n/2;
    string s1=sum2(a,mid);
    string s2=sum2(a+mid,n-mid);    
    return addstring(s1,s2);
}


// Time taken by function sum: 713 microseconds
// Time taken by function sum2: 591 microseconds
void ans(){
    int n;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<sum(a,n)<<endl;
    cout<<sum2(a,n)<<endl;
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
