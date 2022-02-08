#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 // ll gcd(ll a,ll b){
 //    if(b==0)return a;
 //    return gcd(b,a%b);
 // }
 ll gcd(ll a,ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
 }
 int main(){
    ll a,b;
    cin>>a>>b;

    cout<<gcd(a,b)<<"\n";
 }
