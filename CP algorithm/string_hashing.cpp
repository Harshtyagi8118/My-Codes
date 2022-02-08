#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
#define sz(v) (int)v.size()
const int mxn = 29;
int main()
{
    string s;
    cin>>s;
    int n = s.size();
    ll pw[n];
    pw[0]=1;
    for(int i=1;i<n;i++){
        pw[i]=(pw[i-1]*mxn)%mod;
    }
    vector<ll>hash(n+1,0);
    for(int i=0;i<n;i++){
        hash[i+1]= hash[i]+(s[i]-'a')*pw[i];
    }
    for(int i=1;i<=n;i++)cout<<hash[i]<<" ";
    string sub;
    cin>>sub;
    ll subhash =0;
    for(int i=0;i<sz(sub);i++)
        subhash+=((sub[i]-'a')*pw[i])%mod;
    for(int i=0;(i+sz(sub))<=sz(s);i++){
        ll curr = (hash[i+sz(sub)]-hash[i]);
        ll temp = subhash*pw[i];
        cout<<curr<<" "<<temp<<"\n";
        if(curr==temp){cout<<"Found "<<"\n";
        return 0;}

    }
    cout<<"N0t found ";
}