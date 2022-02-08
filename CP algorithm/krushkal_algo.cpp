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
int cost =0;

struct Edge
{
  int u,v ,weight;
  bool operator<(const Edge &other){
    return weight<other.weight;
  }
};
vector<Edge> edge;
vector<Edge> result;
void krushkal_algo(int nodes){
  int n = nodes;
  vector<int>parent(nodes);
  for(int i=0;i<n;i++){
    parent[i]=i;
  }
  sort(edge.begin(),edge.end());
  for(Edge e :edge){
    if(parent[e.u]!=parent[e.v]){
      cost += e.weight;
      result.push_back(e);
      int new_parent = parent[e.u] , old_parent = parent[e.v];
      for(int i=0;i<n;i++){
        if(parent[i]==old_parent){
          parent[i]=new_parent;
        }
      }
    }
  }
}
int main(){
  int vertex,ed;
  cin>>vertex>>ed;
  edge = vector<Edge>(vertex);
  for(int i=0;i<ed;i++){
    int u,v , wt;
    cin>> u >>v>>wt;
    Edge e;
    e.u = u;
    e.v = v;
    e.weight = wt;
    edge.push_back(e);
  }
  krushkal_algo(vertex);
  for(int i=0;i<(int)result.size();i++){
    cout<<result[i].u<<" "<<result[i].v<<" "<<result[i].weight<<" \n";
    cout<<cost<<"\n";
  }

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