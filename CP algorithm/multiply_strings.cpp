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
 string multiply(string num1,string num2){
    int len1 = num1.size();
    int len2 = num2.size();
    int in1=0,in2=0;
    vector<int>result(len1+len2,0);
    for(int i=len1-1;i>=0;i--){
        in2=0;
        int carry=0;
        int n1=num1[i]-'0';
        for(int j=len2-1;j>=0;j--){
            int n2 = num2[j]-'0';
            int sum = n1*n2 + result[in1+in2]+carry;
            carry = sum/10;
            result[in1+in2]=sum%10;
            in2++;
        }
        if(carry>0)
            result[in2+in1]+=carry;
        in1++;
    }
    int i=result.size()-1;
    while(i>=0 && result[i]==0)i--;
    if(i==-1)return "0";
    string s="";
    while(i>=0)
        s+=to_string(result[i--]);
    return s;
 }
 int main(){
    string num1,num2;
    cin>>num1>>num2;
    cout<<multiply(num2,num1)<<"\n";

}
