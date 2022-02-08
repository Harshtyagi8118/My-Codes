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
struct edge
{ 
  int a ,b,cost; 
};
int main(){
  int INF = 1e7;
  int n,m;
  cin>>n>>m;
  vector<edge>e(m);
  for(int i=0;i<m;i++){
    cin>>e[i].a>>e[i].b>>e[i].cost;
  }
  vector<int >p(n,-1);
  vector<int>dis(n,INF);
  dis[0]=0;
  p[0]=-1;
  while(1){
    bool flag = false;
    for(int j=0;j<m;j++){
      if(dis[e[j].a]<INF){
          if(dis[e[j].b]>dis[e[j].a]+e[j].cost){
            dis[e[j].b] = dis[e[j].a]+e[j].cost;
            p[e[j].b] = e[j].a;
            flag = true;
          }
      }
    }
    if(!flag)break;
  }
  int v;
  cout<<"Enter the edge to find the path\n";
  cin>>v;
  if(dis[v]==INF)cout<<"No Path exist\n";
  else{
    vector<int>path;
    for(int curr = v;curr!=-1;curr = p[curr]){
      path.push_back(curr);
    }
    reverse(all(path));
    for(int i=0;i<sz(path);i++){
      cout<<path[i]<<"\n";
    }
  }

}