#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void multi(int m1[3][1],int m2[3][3]){
    int ans[3][1];
    for(int i=0;i<3;i++){
        for(int j=0;j<1;j++){
            ans[i][j]=0;
            for(int k=0;k<3;k++){
                ans[i][j]+=m2[i][k]*m1[k][j];
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            m1[i][j]=ans[i][j];
        }
    }
}
void sq(int m1[3][3],int m2[3][3]){
    int ans[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans[i][j]=0;
            for(int k=0;k<3;k++){
                ans[i][j]+=m2[i][k]*m1[k][j];
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            m1[i][j]=ans[i][j];
        }
    }
}
void power(int b,int m1[3][3]){
    int res[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    while(b){
        if(b&1)sq(res,m1);
        b>>=1;
        sq(m1,m1);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            m1[i][j]= res[i][j];
        }
    }
}
int main(){
    cout<<"Enter the first three elements : ";
    int a,b,c,n;
    cin>>a>>b>>c;
    int m2[3][1] = {c,b,a};
    int m1[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
    cout<<"Enter the term that is to be calculated: ";
    cin>>n;
    power(n-2,m1);
    cout<<"Power matrix is :\n";
    for(int  i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<m1[i][j]<<" ";
        }
        cout<<"\n";
    }
    multi(m2,m1);
    for(int i=0;i<3;i++){
        for(int j=0;j<1;j++){
            cout<<m2[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"nth term is : "<<m2[0][0]<<"\n";
}