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
unordered_map<string,bool>mp;
bool solve(string a,string b){
    if(a.compare(b)==0)return true;
    if(a.length()<=1)return false;
    int n = a.length();
    bool flag = false;
    string str = a;
    str.push_back(' ');
    str+=b;
    if(mp.find(str)!=mp.end())return mp[str];
    for(int i=1;i<=n-1;i++){
        if(solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)) ||
            solve(a.substr(0,i),b.substr(0,i))&&solve(a.substr(i,n-i),b.substr(i,n-i))){flag = true;break;}
    }
    mp[str]=flag;
return flag;
}
int main(){
    string  a,b;
    cin>>a>>b;
    mp.clear();
    if(a.length()!=b.length()){
        cout<<"False\n";
        return 0;
    }
    if(a.empty() && b.empty()){
        cout<<"True\n";
        return 0;
    }
    if(solve(a,b))cout<<"True\n";
    else cout<<"False\n";

}