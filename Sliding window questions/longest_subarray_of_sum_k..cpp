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
    //int ar[]={4,1,1,1,2,3,5};
    //int k =5;
    int sum=0;
    int n;
    cin>>n;
    vector<int>ar(n);
    for(int &i:ar)cin>>i;
    int k;
    cin>>k;
    int mx = 0;
    unordered_map<int,int>um;
    for(int i=0;i<n;i++){
        sum+=ar[i];
        if(sum==k){
            mx = i+1;
        }
        if(um.find(sum)==um.end()){
            um[sum]=i;
        }
        if(um.find(sum-k)!=um.end()){
            if(mx<i-um[sum-k]){
                mx = i - um[sum-k];
            }
        }
    }
    cout<<mx<<"\n";
}