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
bool ispalindrome(string s,int i,int j){
    while(i<=j){
        //cout<<s.substr(i,j-i+1)<<" ";
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
int solve(string s,int i,int j){
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(ispalindrome(s,i,j))return 0;
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++){
        //int temp = solve(s,i,k)+solve(s,k+1,j)+1;
        // or more specific approach 
        int left,right;
        if(dp[i][k]!=-1){
            left = dp[i][k];
        }
        else{
           left= solve(s,i,k);
           dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1){
            right = dp[k+1][j];
        }
        else {
            right = solve(s,k+1,j);
            dp[k+1][j]=right;
        }
        int temp = 1 +left + right;
        if(temp<mn)mn = temp;
    }
    return dp[i][j]= mn;
}
int main(){
    string  s;
    cin>>s;
    cout<<s<<"\n";
    memset(dp,-1,sizeof(dp));
    cout<<solve(s,0,s.size()-1)<<"\n";
}