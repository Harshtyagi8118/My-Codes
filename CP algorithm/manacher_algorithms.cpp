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
int main(){   // longest palindromic substring with best time complixity
    string s;
    cin>>s;
    int n = sz(s);
    n = 2*n+1;
    int l[n];
    l[0]=0;
    l[1]=1;
    int c =1,r =2,id=0,ans=1; 
    for(int i=2;i<n;i++){
        int mir = 2*c-i;
        l[i]=0;
        if(i<r){
            l[i] = min(l[mir],r-i);
        }
        while(i-l[i]-1>=0 && i+l[i]+1<n && ((i+l[i]+1)%2==0 ||
            s[(i-l[i]-1)/2]==s[(i+l[i]+1)/2]))
        {
            l[i]++;
        }
        if(ans<l[i]){
            ans = l[i];
            id=i;
        }
        if(i+l[i]>r){
            r = i+l[i];
            c=i;
        }
    }
    for(int i=0;i<n;i++)cout<<l[i]<<" ";
        cout<<"\n"<<s.substr((id-ans)/2,ans)<<"\n";
}