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
// 2*x -const ->x // const = num of array
 ll dp[3000][3000][2];
// dp[l][r][p] = {l.......r}inclusive ,pth player turn std 
 // p =0 ->first , p= 1-?second

// base cases
// dp[i][i][0] = a[i];
// dp[i][i][1] = 0;

 // Transitions
 // pick l or pich r
 // dp[l][r][0] = max(a[l]+dp[l+1][r][1], a[r] + dp[l][r-1][1]);
 // dp[l][r][1] = min(dp[l+1][r][0],dp[l][r-1][0] );

//Order of Evauation
//(r-l )is decreasing 
//  we need incresding of (r-l)  

// ans = 2*(dp[0][n-1][0]) - const
  int main()
  {
    ll n;
    cin>>n;
    vector<int>a(n);
    for(auto &i :a)cin>>i;
    for(ll i=0;i<n;i++){
        dp[i][i][0] = a[i];
        dp[i][i][1]=0;

    }
    ll sum=0;
    for(ll i:a)sum+=i;
    for(ll rminusl = 1;rminusl < n; rminusl++){
        for(ll l=0;l+rminusl<n;l++){
            ll r = l+rminusl;
            dp[l][r][0] = max(a[l] + dp[l+1][r][1],a[r] + dp[l][r-1][1] ); 

            dp[l][r][1] = min(dp[l+1][r][0],dp[l][r-1][0]);
        }
    }  
    ll x = dp[0][n-1][0];

      ll ans = 2*x -sum;
      cout<<ans<<"\n";
  }