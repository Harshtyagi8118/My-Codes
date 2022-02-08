#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int mx = 1e5+1;
int vis[mx];
vector<int> adj[mx];
int n,m;
void dfs(int x){
	vis[x]=1;
	for(auto i : adj[x]){
		if(!vis[i])dfs(i);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int temp=0;
	vector<int>ans;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			temp++;
			ans.push_back(i);
		}
	}
	temp--;
	cout<<temp<<" \n";
	if(temp){
		for(int i=0;i<ans.size()-1;i++){
			cout<<ans[i]<<" "<<ans[i+1]<<"\n";
		}
	}
}