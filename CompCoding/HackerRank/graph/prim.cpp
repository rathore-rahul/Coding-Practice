#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i =0; i < n ;i++)
#define INF 1E9
const int max_nodes = 3*(1E3)+1;
typedef pair<int,int> pi;
vector<pair<int,int> > edges[max_nodes];

int main(){
  int n,m,x,y,r,s;
  cin>>n>>m;
  rep(i,m){
    cin>>x>>y>>r;
    x--;y--;
    edges[x].push_back({r,y});
    edges[y].push_back({r,x});
  }
  vector<int> key(n,INF);
  vector<bool> visited(n,false);
  cin>>s;
  s--;
  int ans = 0;
  priority_queue<pi,vector<pi>, greater<pi> > pq;
  pq.push({0,s});
  key[s] = 0;
  while(!pq.empty()){
    pi temp = pq.top();
    pq.pop();
    if(visited[temp.second])
        continue;
    ans += temp.first;
    visited[temp.second] = true;
    for(auto it : edges[temp.second]){
      int w = it.first;
      int v = it.second;
      if(!visited[v] && w < key[v]){
        pq.push({w,v});
        key[v] = w;
      }
    }
  }
  cout<<ans<<endl;
}
