#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int mxn =1e6+1;
int vis[mxn];
int lowerprime[mxn];
vector<int> prime;
void sieve(){
    lowerprime[1]=1;
    for(int i=2;i<mxn;i++){
        if(vis[i]==0)
            prime.push_back(i);
        for(int j=i;j<mxn;j+=i){
            if(vis[j]==0){
                vis[j]=1;
                lowerprime[j]=i;
            }
        }
    }
}
ll factorial[mxn];
int main(){
    int n;
    factorial[0]=1;
    cin>>n;
    for(int i=1;i<=mxn;i++){
        factorial[i] = factorial[i-1]*i;
    }
    //cout<<factorial[n];
    sieve();
    for(int i=0;i<20;i++)cout<<prime[i]<<" ";
        cout<<"\n";
    for(int i=0;i<20;i++)cout<<lowerprime[i]<<" ";
    cout<<"\n";
    while(n!=1){
        cout<<lowerprime[n]<<" ";
        n /=lowerprime[n];
    }
}