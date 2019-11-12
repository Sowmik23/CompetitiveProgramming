#include<bits/stdc++.h>
using namespace std;
string a;
set<pair<long long,long long> >st;
long long dao(string s,long long mod,long long b)
{
    long long hsh=0;
    long long p=1;
    for(int i=0;i<s.length();++i)
    {
        hsh+=(p*s[i]);
        p=(p*b)%mod;
        hsh%=mod;
    }
    return hsh;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a;
        st.insert({dao(a,(1e9)+7,999983),dao(a,(1e9)+9,257)});


    }
    cin>>n;
    while(n--)
    {

        cin>>a;
        long long f=dao(a,(1e9)+7,999983),ss=dao(a,(1e9)+9,257);
        if(st.find({f,ss})==st.end()) puts("no");
        else puts("yes");
    }


}
