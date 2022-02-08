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
    int cn[]={1,2,3};
    int sum=5;
    int dp[4][sum+1];
    for(int i=0;i<4;i++)dp[i][0]=0;
    for(int i=0;i<=sum;i++)dp[0][i]=INT_MAX-1;
    for(int j=1;j<=sum;j++){
        if(j%cn[0]==0){
            dp[1][j]=j/cn[0];
        }
        else dp[1][j]=dp[0][j];
    }    
    for(int i=2;i<4;i++){
        for(int j=1;j<=sum;j++){
            if(cn[i-1]<=j)dp[i][j]=min(1+dp[i][j-cn[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<dp[3][sum]<<"\n";
}