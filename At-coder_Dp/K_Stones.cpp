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
int dp[1000005];
int main(){
 int n,k;
 cin>>n>>k;
 int arr[n];
 for(int &i:arr)cin>>i;
 dp[0]=0;
 for(int i=1;i<=k;i++){
    dp[i]=0;
    for(int x:arr){
        if(i>=x && dp[i-x]==0)dp[i]=1;
    }
 }
 if(dp[k]==1)cout<<"First";
 else cout<<"Second";
 return 0;   
}