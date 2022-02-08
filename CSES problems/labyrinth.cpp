#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
//vector<string> adj;
int n,m,sx,sy,dx,dy,X[]={0,0,1,-1},Y[]={1,-1,0,0};
char adj[1000][1000];
int vis[1000][1000];
char turn[] = {'L','R','U','D'};
bool valid(int i , int j){
	if(i<0 || i>=n || j<0 || j>=m)return false;
	return true;
}
void recover_path(int x,int y,string &s ){
	if( x == sx && y == sy)return ;
	for(int i=0;i<4;i++){
		int xx = x + X[i];
		int yy = y + Y[i];
		if(valid(xx,yy) && vis[xx][yy] ==  vis[x][y]-1){
			s+=turn[i];
			recover_path(xx,yy,s);
			return;
		}
	}
}
void bfs(int x,int y)
{
	vis[x][y]=1;
	queue<array<int,2>> q;
	q.push({x,y});
	while(!q.empty()){
		array<int,2> temp = q.front();
		q.pop();
		x = temp[0];
		y = temp[1];
		for(int i=0;i<4;i++){
			int xx = x+X[i];
			int yy = y+Y[i];
			if(valid(xx,yy) && (adj[xx][yy]=='.')){
				q.push({xx,yy});
				adj[xx][yy]='#';
				vis[xx][yy] = 1+vis[x][y];
			}
		}
	}

}
int main(){
	cin>>n>>m;
	//adj = vector<string>(n);
	for(int i = 0;i<n;i++){
		for(int j=0;j<m;j++){
			vis[i][j]=0;
			cin>>adj[i][j];
			if(adj[i][j]=='A')
			{
				sx = i;
				sy = j;
			}
			else if(adj[i][j]=='B'){
				dx = i;
				dy = j;
				adj[i][j]='.';
			}
		}
	}
	bfs(sx,sy);
	if(vis[dx][dy]!=0){
		string s="";
		recover_path(dx,dy,s);
		reverse(s.begin(),s.end());
		int a = s.size();
		cout<<"YES\n"<<a<<'\n'<<s<<"\n";
	}
	else
		cout<<"NO";

}