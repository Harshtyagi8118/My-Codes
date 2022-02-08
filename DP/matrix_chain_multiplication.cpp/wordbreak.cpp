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
bool match(string s){
    string a[]={"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int size = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size;i++){
        if(a[i].compare(s)==0)return true;
    }
    return false;
}
bool solve(string s){
    int size = s.size();
    if(size==0)return true;
    for(int i=1;i<=size;i++){
        if(match(s.substr(0,i))&&solve(s.substr(i,size-i)))return true;
    }
    return false;
}
int main(){
    
    solve("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    solve("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    solve("")? cout <<"Yes\n": cout << "No\n";
    solve("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    solve("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    solve("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}