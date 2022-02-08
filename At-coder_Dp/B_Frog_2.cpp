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
        int n,k;
        cin>>n>>k;
        int ar[n];
        for(int i=0;i<n;i++)cin>>ar[i];
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=k+i && j<n ;j++){
                dp[j] = min(dp[j],dp[i]+abs(ar[i]-ar[j]));
            }
    }
    cout<<dp[n-1]<<"\n";
       
}