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
    string s="aabacbebebe";
    int k = 3;
    int i=0;
    int j = 0;
    int mx = 0;
    unordered_map<char,int>m;
    while(j<sz(s)){
        m[s[j]]++;
        if(sz(m)<k)j++;
        else if(sz(m)==k){
            mx = max(mx,j-i+1);
            j++;
        }
        else {
            while(sz(m)>k){
                m[s[i]]--;
                if(m[s[i]]==0)m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    cout<<mx<<"\n";
}