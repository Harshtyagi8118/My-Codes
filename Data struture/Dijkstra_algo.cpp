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
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
const int mxn = 1e5+1;
vector<pair<int,int>> adj[mxn];
int dp[mxn],parent[mxn];
int e,n;
void dj(int src){
	set<pair<int,int>> s;

	for(int i=0;i<mxn;i++){
		dp[i] = INT_MAX;
	}

	dp[src] =0;

	s.insert(mk(dp[src],src));

	while(!s.empty()){
		auto from = *s.begin();

		s.erase(s.begin());

		for(pair<int,int> to : adj[from.ss]){

			int dis =  dp[from.ss]+to.ss;
			if(dis < dp[to.ff]){

				s.erase(mk(dp[to.ff],to.ff));
				dp[to.ff] = dis;

				//parent[to.ff] = from.ss;

				s.insert(mk(dp[to.ff],to.ff));
			}
		}
	}
	for(int i=0;i<n;i++) cout<<i<<" "<<dp[i]<<"\n";
}
int main(void)
{
	FIO	
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[v].pb(mk(u,w));
		adj[u].pb(mk(v,w));
	}
	dj(0);
	return 0;
}

// 9
// 14
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 7 8 7
// 7 6 1
// 8 6 6
// 2 8 2
// 2 3 7
// 2 5 4
// 6 5 2
// 3 5 14 
// 5 4 10
// 3 4 9
// .........................................with minimum path
// #include <bits/stdc++.h>
// using namespace std;
// #define ld double
// #define ll long long
// #define pb emplace_back
// #define mk make_pair
// #define mod 1000000007
// #define ff first
// #define ss second
// #define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define all(x) x.begin(),x.end()
// #define sz(v) (int)v.size()
// const int mx =1001;
// int dp[mx];
// vector<pair<int,int>>adj[mx];
// vector<int>p(mx);
// int n,e;
// void dj(int src){
//     for(int i=0;i<mx;i++){
//         dp[i]=INT_MAX;
//     }
//     set<pair<int,int>>s;
//     dp[src]=0;
//     s.insert(mk(dp[src],src));
//     while(!s.empty()){
//         auto from = *s.begin();
//         s.erase(s.begin());
//         for(pair<int,int> to : adj[from.ss]){
//             int dis = dp[from.ss]+to.ss;
//             if(dis<dp[to.ff]){
//                 s.erase(mk(dp[to.ff],to.ff));
//                 dp[to.ff]=dis;
//                 s.insert(mk(dp[to.ff],to.ff));
//                 p[to.ff]=from.ss;
//             }
//         }
//     }
//     for(int i=0;i<n;i++)cout<<i<<" "<<dp[i]<<"\n";
//      //for(int i=0;i<n;i++)cout<<p[i]<<"\n"; 
//     std::vector<int> v;
//     for(int i = 4;p[i]!=-1;i=p[i])v.push_back(i);
//     v.push_back(0);
//     for(int i=0;i<v.size();i++)cout<<v[i]<<" ";   
        
// }
// int main(){
//     cin>>n>>e;
//     for(int i=0;i<n;i++){
//         p[i]=-1;
//     }
//     for(int i=0;i<e;i++){
//         int u,v,w;
//         cin>>u>>v>>w;
//         adj[u].pb(mk(v,w));
//         adj[v].pb(mk(u,w));
//     }
//     dj(0);
// }