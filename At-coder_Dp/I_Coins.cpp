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
double dp[3000][3000]; // dp[index][number of heads up to index]
double p[3000];
int main(){
    int n;
    cin>>n;
    for(int i;i<n;i++){
        cin>>p[i];
    }
    dp[0][0] = 1-p[0];
    dp[0][1]=p[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            //tails
            dp[i][j] += dp[i-1][j]*(1-p[i]);
            //heads
            if(j>0)
            dp[i][j] += p[i]*dp[i-1][j-1];
        }
    }
    double ans=0;
    for(int i=n/2+1;i<=n;i++){
        ans+=dp[n-1][i];
    }
    cout<<setprecision(9);
    cout<<fixed;
    cout<<ans<<"\n";
}