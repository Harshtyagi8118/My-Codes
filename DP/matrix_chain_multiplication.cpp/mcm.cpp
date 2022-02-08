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
int dp[1001][1001];
int solve(int arr[],int i,int j){
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int term = solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(term<mn){
            mn = term;
        }
    }
    return dp[i][j]= mn;
}
int main(){
    int ar[]={40,20,30,10,30};
    memset(dp,-1,sizeof(dp));
    cout<<solve(ar,1,4)<<"\n";
}