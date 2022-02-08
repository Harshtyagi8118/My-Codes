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
        int n;
        cin>>n;
        int A=0,B=0,C=0;
        for(int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            a+=max(C,B);
            b+=max(A,C);
            c+=max(A,B);
            A =a;B=b;C=c;        
        }
        cout<<max({A,B,C})<<"\n";
     
    }