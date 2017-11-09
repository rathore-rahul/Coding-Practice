#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i =0; i < n ;i++)

const int max_nodes = 1E5+1;

vector<int> edges[max_nodes];
vector<int> parent(max_nodes);
std::vector<pair<int,int> > idxs(max_nodes);
int node_num;
void dfs(int root ,int p){
  parent[root] = p;
  idxs[root].first = node_num;
  node_num++;
  for(int i = 0; i < edges[root].size();i++){
    if(edges[root][i] == p){ continue;}
    dfs(edges[root][i],root);
  }
  idxs[root].second = node_num;
}

int main(){
    std::ios::sync_with_stdio(false);
    int q,n,k,u,v,g;
    cin>>q;
    while(q--){
      cin>>n;
      vector<int> seg_sum(n+1);
      node_num = 0;
      rep(i,n-1){
        cin>>u>>v;
        u--;v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
      }
      cin>>g>>k;

      parent.assign(n,-1);
      dfs(0,-1);
      rep(i,g){
        cin>>u>>v;
        u--;v--;
        if(parent[v] == u){
          seg_sum[idxs[0].first]++;
          seg_sum[idxs[0].second]--;
          seg_sum[idxs[v].first]--;
          seg_sum[idxs[v].second]++;
        }
        else{
          seg_sum[idxs[u].first]++;
          seg_sum[idxs[u].second]--;
        }
      }
      int counter = 0;
      int cum_sum = 0;
      rep(i,n){
        cum_sum += seg_sum[i];
        if(cum_sum >= k)
          counter++;
      }
      int gcd = __gcd(counter,n);
      printf("%d/%d\n",counter/gcd,n/gcd);
      rep(i,max_nodes){
        edges[i].clear();
      }
    }
}
