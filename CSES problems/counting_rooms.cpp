#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<string> adj;
int n,m,X[] = {0,0,1,-1},Y[]= {1,-1,0,0};
vector<vector<bool>>vis;
bool valid(int i,int j){
	if(i<0||j<0||i>=n||j>=m || vis[i][j]==1)return false;
	return true;
}
bool dfs(int x,int y){
	vis[x][y]=1;
	bool res = true;
	for(int i=0;i<4;i++){
	
			int xx =  x + X[i];
			int yy =  y + Y[i];
			if(valid(xx,yy) && adj[xx][yy]=='.'){
				res &=dfs(xx,yy);
			}
		}
		return res;	
}
int main(){
	cin>>n>>m;
	adj = vector<string>(n);
	for(auto &i : adj)cin>>i;
	vis.assign(n,vector<bool>(m,false));
int ans =0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(adj[i][j]=='.' && !vis[i][j]){
				if(dfs(i,j))ans++;
			}
		}
	}	
	cout<<ans;
}