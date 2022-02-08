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
int v,e;
vector<vector<int>>adj;
vector<int>dp;
vector<bool>vis;
int dfs(int node){
    if(vis[node])return dp[node];
    else{
        vis[node]=true;
        int temp=0,max_val=0;
        for(int it:adj[node]){
            
            temp = 1+dfs(it);
            max_val = max(temp,max_val);
        
        }
        dp[node]=max_val;
    }
    return dp[node];
}
int main(){
    cin>>v>>e;
    adj = vector<vector<int>>(v);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    for(int i=0;i<v;i++){
        dp.pb(0);
        vis.pb(false);
    }
    int ans =0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            //dp[i]=dfs(i);
            ans =max(ans,dfs(i));
        }
    }
    cout<<ans<<"\n";
}
