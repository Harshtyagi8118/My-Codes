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
bool ifanagram(string s1,string s2){
    map<char,int>m;
    for(int i=0;i<s1.size();i++){
        m[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++){
        m[s2[i]]--;
    }
    for(auto it:m){
        if(it.second!=0)return false;
    }
    return true;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m= s2.size();
    int i=0,j=0;
    int res=0;
    for(int i=0;i<n-m+1;i++){
        if(ifanagram(s1.substr(i,m),s2))res++;
    }
    cout<<res<<" \n";
}