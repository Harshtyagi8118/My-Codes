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
int main(){
    int h,w;
    cin>>h>>w;
    vector<string>adj(h);
    for(auto &i:adj)cin>>i;
    vector<vector<int>>dp(h,vector<int>(w,0));
    dp[0][0]=1;
    for(int i=1;i<h;i++){
        if(adj[i][0]=='#')dp[i][0]=0;
        else dp[i][0]=dp[i-1][0];
    }
    for(int i=1;i<w;i++){
        if(adj[0][i]=='#')dp[0][i]=0;
        else dp[0][i]=dp[0][i-1];
    }    
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(adj[i][j]=='.'){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    cout<<dp[h-1][w-1]<<"\n";
}