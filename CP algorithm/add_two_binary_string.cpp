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
    string a,b;
    cin>>a>>b;
    int s=0;
    string ans="";
    int i=a.size()-1,j=b.size()-1;
    while(i>=0 || j>=0 ||s==1){
        s+=((i>=0)?a[i]-'0':0);
        s+=((j>=0)?b[i]-'0':0);
        ans+=char(s%2+'0');
        s/=2;
        i--;j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<" \n";
}