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
    const ll maxx =2*1e18;
    int main()
    {
        ll n,W;
        cin>>n>>W;
        vector<ll>v(n+1),w(n+1);
        ll value=0;
        for(int i=1;i<=n;i++){
            cin>>w[i]>>v[i];
            value+=v[i];
        }
        vector<ll>dp(value+1,maxx);
        dp[0]=0;
        for(int i =1;i<=n;i++){
            for(int val = value;val>=v[i] ; val--){
                dp[val]=min(dp[val],dp[val-v[i]]+(ll)w[i]);
            }
        }
        for(int i=value;i>=0;i--){
            if(dp[i]<=W){
                cout<<i<<"\n";
                return 0;
            }
        }
    }