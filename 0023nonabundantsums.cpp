#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//using namespace chrono;
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define ld              long double
#define fr(i,n)         for(int i=0;i<n;i++)
#define fro(i,k,n)      for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define py              cout<<"YES"<<endl;
#define pn              cout<<"NO"<<endl;
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ull             unsigned long long
#define in              cin>>
#define o(x)            cout<<x<<endl;
#define pi              3.1415926535897932
#define mod             1000000007
#define inf             1e18
#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define all(x)          x.begin(), x.end()
#define allr(x)          x.end(), x.begin()
#define clr(x)          memset(x, 0, sizeof(x))
#define sortall(x)      sort(all(x))
#define tr(it, a)       for(auto it = a.begin(); it != a.end(); it++)
#define mk(a,n,type)    type *a=new type[n];
#define ps(x,y)         fixed<<setprecision(y)<<x

typedef pair< int,int >                 pll;
typedef vector<int>                     vll;
typedef vector<pll>                     vpll;
typedef vector<string>                  vs;
typedef unordered_map<int,int>          umll;
typedef map<int,int>                    mll;
typedef priority_queue<int>             pqllmax;
typedef priority_queue<int,vector<int>,greater<int>>             pqllmin;
typedef pair<int32_t,int32_t>           pii;
typedef vector<int32_t>                 vi;
typedef vector<pii>                     vpi;
typedef vector<string>                  vs;
typedef unordered_map<int32_t,int32_t>  umi;
typedef map<int32_t,int32_t>            mi;
typedef priority_queue<int>             pqimax;
typedef priority_queue<int,vector<int>,greater<int>>             pqimin;

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

template <typename T>
void print(T &&t)  { cout << t << endl; }
template<typename T>
void printvec(vector<T>v){int n=v.size();fr(i,n){cout<<v[i]<<" ";cout<<endl;}}
template<typename T>
int sumvec(vector<T>v){int n=v.size();int s=0;fr(i,n){s+=v[i];}return s;}

void pa(int* a,int n){for (int i = 0; i < n ; i++){cout<<a[i]<<" ";}}
int count(int* a,int n,int ele){int c=0;for(int i=0;i<n;i++){if(a[i]==ele){c+=1;}}return c;}
int index(int* a,int n,int ele){for(int i=0;i<n;i++){if(a[i]==ele){return i;}}return -1;}
int sum(int* a,int n){int s=0;for(int i=0;i<n;i++){s+=a[i];}return s;}
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
// Mathematical functions
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
int lcm(int a, int b){return (a/gcd(a,b)*b);}
int expmod(int x, int y, int p){int res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
bool twop(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool sq(int x){if(x >= 0){int sr = sqrt(x);return (sr * sr == x);}return false;}
bool prime(int n) {if(n==1){return false;}for(int i=2;i*i<n;i++){if(n%i==0){return false;}}return true;}
int modadd(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int modmul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int modsub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int power(int a,int b) {if(b==0){return 1;}int res=power(a, b / 2);if (b % 2){return res*res*a;}else{return res*res;}}
template<typename T>
void printmat(T a,int n,int m){for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<*(*(a+i)+j)<<" ";}cout<<endl;}}

//let us call the numbers that can be written as the sum of two abundant numbers as good numbers
umll isabundant;
umll isgood;
// this functionchecks whether a number is abundant or not
// it also updates the isabundant map
// ans also updates the isgood map with good numbers which have one of the abundant numbers as n
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
    for(auto i:isabundant){
        if(i.first+n<=28123){
            isgood[i.first+n]=1;
        }
    }
}



void ans(){
    int n=28123;
    for(int i=1;i<=n;i++){
        abundant(i);
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
