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
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)cin>>ar[i];
        int dp[n+1];
        dp[0]=0;
        dp[1]=0;
       for(int i=2;i<=n;i++){
            dp[i] = min(dp[i-1]+abs(ar[i-1]-ar[i-2]),dp[i-2]+abs(ar[i-1]-ar[i-3]));       
        }    
        cout<<dp[n]<<"\n";
    }