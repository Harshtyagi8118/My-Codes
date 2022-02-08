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
int un_knsp(int price[],int len[],int n,int max_len){
    if(max_len==0||n==0)return 0;
    if(max_len>=len[n-1]){
        return max(price[n-1]+un_knsp(price,len,n,max_len-len[n-1]),un_knsp(price,len,n-1,max_len));
    }
    else return un_knsp(price,len,n-1,max_len);
}
int main(){
    int price[]={1, 5, 8, 9, 10, 17, 17, 20};
    int len[]={1,2,3,4,5,6,7,8};
    cout<<un_knsp(price,len,8,8)<<" \n";
}