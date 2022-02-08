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
    int ar[]={12,-1,-7,8,-15,30,18,28};
    list<int>l;
    int k=3;
    vector<int>v;
    int i=0,j=0;
    while(j<8){
        if(ar[j]<0)l.push_back(ar[j]);
        if(j-i+1<k){
            j++;}
        else if(j-i+1==k){
            if(l.size()==0)v.push_back(0);
            else{v.push_back(l.front());
                if(ar[i]==l.front())l.pop_front();   
            }
            i++;
            j++;
        }
    }
        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    
}