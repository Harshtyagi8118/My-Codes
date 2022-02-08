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
void create_lps(string pat,int m,int *lps){
    lps[0]=0;
    int len =0;
    int i=1;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else {
            if(len!=0){
                len = lps[len-1];
            }
            else {
                lps[i]=0;
                i++;
            }
        }
    }
}
int KMP_search(string main,string pat){  // For pattern searching 
    int m =pat.size();
    int n = main.size();
    int i=0;
    int j=0;
    int lps[m];
    create_lps(pat,m,lps);
    while(i<n && j<m){
        if(pat[j]==main[i]){
            j++;
            i++;
        }
        else {
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j==m){
           return  i-j; 
        }
        
    }
    return -1;

}
int main(){
    string p,s;
    cin>>p>>s;
    cout<<KMP_search(p,s);

}