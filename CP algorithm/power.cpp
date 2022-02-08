#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll power(ll a,ll b){
    ll ans =1;
    while(b>0){
        if(b&1)ans = ans*a;
        a = a*a;
        b>>=1;
    }
    return ans;
}
int main(){
    ll a,b;
    cin>>a>>b;
    cout<<power(a,b)<<"\n";
}