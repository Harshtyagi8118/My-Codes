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
    int ar[]={2,3,5,2,9,7,1};
    int sum1 = 0,k=3;
    int ans=INT_MIN;
    // for(int i=0;i<3;i++){
    //     sum1+=ar[i];
    // }
    // int sum2=0;
    // for(int i=3;i<7;i++){
    //     sum2=sum1+ar[i]-ar[i-3];
    //     ans=max(sum1,sum2);
    //     sum1=sum2;
    // }
    // better one solution
    int j=0,i=0;
    while(j<7){
        sum1+=ar[j];
        if(j-i+1<k)j++;
        else if(j-i+1==k){
            ans=max(ans,sum1);
            sum1-=ar[i];
            i++;
            j++;
        }
    }
    cout<<ans<<" \n";
}