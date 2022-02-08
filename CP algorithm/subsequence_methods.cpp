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
bool is_subsequence(string a,string b,int n,int m){
    //int n = sz(a);
    //int m = sz(b);
    if(m==0)return true;
    if(n==0)return false;
    if(a[n]==b[m])return is_subsequence(a,b,n-1,m-1);
    else return is_subsequence(a,b,n-1,m);

}
int main(){
    string a,b;
    cin>>a>>b;
    int n = sz(a);
    int m = sz(b);
    // int j=0;
    // for(int i=0;i<n && j<m ;i++){
    //     if(a[i]==b[j])j++;
    //     if(j==m){cout<<"\n"<<b<<" is subsquence of "<<a<<"\n";return 0;}
    // }
    // cout<<"not a subsequece \n";
    // return 0;
    if(is_subsequence(a,b,n-1,m-1))cout<<"Is subsequence \n";
    else cout<<"Not a subsequence \n";
}
