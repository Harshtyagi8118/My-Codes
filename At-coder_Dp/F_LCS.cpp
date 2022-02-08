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
        string s,t;
        cin>>s>>t;
        int n = sz(s);
        int m = sz(t);
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)dp[i][j]=0;
                else if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        string ans="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans+=s[i-1];
                i--;
                j--;
            }
            
               else if(dp[i-1][j]>dp[i][j-1])i--;
                else j--;
            
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<"\n";
    }