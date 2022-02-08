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
    double dp[301][301][301];
    int main(){
        int n;
        cin>>n;
        int cnt[4]={0};
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            cnt[x]++;
        }
        for(int three =0;three<=n;three++){
            for(int two = 0;two<=n;two++){
                for(int one =0;one<=n;one++){
                    int zero = n -one - two- three;
                    if(zero==n)continue;
                    if(one+two+three>n)continue;
                    double val=1;
                    if(three>0)val+=(1.0*three/n)*dp[three-1][two+1][one];
                    if(two>0)val+=(1.0*two/n)*dp[three][two-1][one+1];
                    if(one>0)val+=(1.0*one/n)*dp[three][two][one-1];
                    dp[three][two][one] = val/(1- 1.0*zero/n);
                
                }
            }
        }
        cout<<setprecision(9);
        cout<<fixed;
        cout<<dp[cnt[3]][cnt[2]][cnt[1]]<<"\n";
    }