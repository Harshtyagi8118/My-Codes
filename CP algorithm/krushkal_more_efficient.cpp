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
struct Edge
{
  int u,v,weight;
  bool operator<(const Edge&other){
    return weight<other.weight;
  }
};
int cost =0;
vector<Edge>edges,result;
vector<int>parent,rnk;
void make_set(int v){
  parent[v]=v;
  rnk[v]=0;
}
int find_set(int v){
  if(v==parent[v])return v;
  return parent[v] = find_set(parent[v]);
}
void union_set(int a,int b){
  a = find_set(a);
  b = find_set(b);
  if(a!=b){
    if(rnk[a]<rnk[b])swap(a,b);
    parent[b]=a;
    if(rnk[a]==rnk[b])rnk[a]++;
  }
}
void krushkal_algo(int n){
  parent.resize(n);
  rnk.resize(n);
  for(int i=0;i<n;i++)make_set(i);
    sort(edges.begin(),edges.end());
  for(Edge e:edges){
    if(find_set(e.u)!=find_set(e.v)){
      cost+=e.weight;
      result.push_back(e);
      union_set(e.u,e.v);
    }
  }  
}
int main(){
  int vertex,ed;
  cin>>vertex>>ed;
  edges = vector<Edge>(vertex);
  for(int i=0;i<ed;i++){
    int u,v , wt;
    cin>> u >>v>>wt;
    Edge e;
    e.u = u;
    e.v = v;
    e.weight = wt;
    edges.push_back(e);
  }
  krushkal_algo(vertex);
  for(int i=0;i<(int)result.size();i++){
    cout<<result[i].u<<" "<<result[i].v<<" "<<result[i].weight<<" \n";  
  }
  cout<<cost<<"\n";

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