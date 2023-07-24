#include<bits/stdc++.h>
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define o(x)            cout<<x<<endl;

// function taken frpm geeksforgeeks to convert number to words
int numtowordlen(long long n){
    if(n==1000){return 11;}
    long long limit = 1000000000000,curr_hun, t = 0;
    if (n == 0)
        return 4;
    string multiplier[] = { "","Thousand"};
    string first_twenty[] = {
        "",        "One",       "Two",      "Three",
        "Four",    "Five",      "Six",      "Seven",
        "Eight",   "Nine",      "Ten",      "Eleven",
        "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    string tens[]
        = { "",      "Twenty",  "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety" };
    if (n < 20)
        return (first_twenty[n]).size();
    string answer = "";
    for (long long i = n; i > 0;
         i %= limit, limit /= 1000) {
        curr_hun = i / limit;
        while (curr_hun == 0) {
            i %= limit;
            limit /= 1000;
            curr_hun = i / limit;
            ++t;
        }
        if (curr_hun > 99)
            answer += (first_twenty[curr_hun / 100]+ "Hundred");
        curr_hun = curr_hun % 100;
        if(curr_hun>0 && answer.size()>0){answer+="and";}
        if (curr_hun > 0 && curr_hun < 20)
            answer += (first_twenty[curr_hun]);
        else if (curr_hun % 10 == 0 && curr_hun != 0)
            answer += (tens[curr_hun / 10 - 1]);
        else if (curr_hun > 20 && curr_hun < 100)
            answer += (tens[curr_hun / 10 - 1] + first_twenty[curr_hun % 10]);
        if (t < 4)
            answer += (multiplier[++t]);
    }
    return (answer).size();
}


void ans(){
    int n;
    cin>>n;
    int totalletters=0;
    for(int i=1;i<=n;i++){
        totalletters+=(numtowordlen(i));
    }
    o(totalletters)
}
int32_t main(){
    fast
    //int t;cin>>t;
    int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
