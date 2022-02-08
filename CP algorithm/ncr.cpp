#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll factotial(ll n){
    if(n==0)return 1;
    else return factotial(n-1)*n;
}
ll power(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b&1)ans*=a;
        b>>=1;
        a = a*a;
    }
    return ans;
}
ll invmod(ll b){
    return power(b,mod - 2);
}
ll ncr(ll n,ll r){
    if(n<r)return 0;
    else return factotial(n)/(factotial(n-r)*factotial(r));
}
int main(){
    ll n,r;
    cin>>n>>r;
    cout<<ncr(n,r)<<"\n";
}