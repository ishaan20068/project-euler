// find the digit sum of n!
#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define o(x)            cout<<x<<endl;

string add(string a,string b){
    int n=a.size();
    int m=b.size();
    int carry=0;
    string ans="";
    int i=n-1,j=m-1;
    while(i>=0 && j>=0){
        int x=a[i]-'0';
        int y=b[j]-'0';
        int z=x+y+carry;
        carry=z/10;
        z=z%10;
        ans+=to_string(z);
        i--;
        j--;
    }
    while(i>=0){
        int x=a[i]-'0';
        int z=x+carry;
        carry=z/10;
        z=z%10;
        ans+=to_string(z);
        i--;
    }
    while(j>=0){
        int y=b[j]-'0';
        int z=y+carry;
        carry=z/10;
        z=z%10;
        ans+=to_string(z);
        j--;
    }
    if(carry!=0){
        ans+=to_string(carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


string mul(string a,char b){
    int n=a.size();
    int x=b-'0';
    int carry=0;
    string ans="";
    for(int i=n-1;i>=0;i--){
        int y=a[i]-'0';
        int z=x*y+carry;
        carry=z/10;
        z=z%10;
        ans+=to_string(z);
    }
    if(carry!=0){
        ans+=to_string(carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string multiplystrings(string a,string b){
    int n=a.size();
    int m=b.size();
    string ans="0";
    for(int i=m-1;i>=0;i--){
        string temp=mul(a,b[i]);
        for(int j=0;j<m-1-i;j++){
            temp+="0";
        }
        ans=add(ans,temp);
    }
    return ans;

}

void ans(){
    int n;
    cin>>n;
    string ans="1";
    for(int i=2;i<=n;i++){
        ans=multiplystrings(ans,to_string(i));
    }
    int sum=0;
    for(int i=0;i<ans.size();i++){
        sum+=ans[i]-'0';
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
