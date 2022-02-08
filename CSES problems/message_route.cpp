#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int mx = 1e5+1;
//vector<int> adj[mx];
//void bfs(int i){

int n,m;
int main(){
	cin>>n>>m;
	vector<int>adj[n+1];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int>q;
	q.push(1);
	int parent[n+1]={0};
	while(!q.empty()){
		int u =q.front();
		q.pop();
		for(int i : adj[u]){
			if(parent[i]==0){
				parent[i]=u;
				q.push(i);
			}
		}}
		vector<int>ans;
		if(!parent[n])cout<<"IMPOSSIBLE\n";
		else{
			vector<int>ans;
			ans.push_back(n);
			for(int i = parent[n] ;i!=1;i = parent[i])ans.push_back(i);
				ans.push_back(1);
			cout<<ans.size()<<"\n";
				for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
		}
	}

