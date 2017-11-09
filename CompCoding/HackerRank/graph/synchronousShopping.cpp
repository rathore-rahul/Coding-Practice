#include <bits/stdc++.h>
using namespace std;
#define INF 1E9
#define rep(i,n) for(int i =0; i < n ;i++)
typedef pair<int,pair<int,int> > heap_node;

const int max_nodes = 1E4+1,max_mask = 1024+1;

vector<vector<int> > dist(max_nodes,vector<int>(max_mask,INF));
int ft[max_nodes];
int n,m,k,temp,t;
priority_queue<heap_node, vector<heap_node> , greater<heap_node> > pq;
vector<pair<int,int> > adjlist[max_nodes];

int main(){
    cin>>n>>m>>k;
    rep(i,n){
      cin>>t;
      rep(j,t){
        cin>>temp;
        temp--;
        ft[i] |= (1<<temp);
      }
    }
    rep(i,m){
      int a,b,w;
      cin>>a>>b>>w;
      a--;b--;
      adjlist[a].push_back({b,w});
      adjlist[b].push_back({a,w});
    }
      pq.push({0,{0,ft[0]}});
      while (!pq.empty()) {
        heap_node temp_node = pq.top();
        pq.pop();
        int node_num = temp_node.second.first;
        int curr_time = temp_node.first;
        int curr_mask = temp_node.second.second;
        for(auto it = adjlist[node_num].begin(); it != adjlist[node_num].end(); it++){
          int dest_node = it->first;
          int dest_time = curr_time + it->second;
          int dest_mask = ft[dest_node] | curr_mask;
          if(dist[dest_node][dest_mask] > dest_time){
            dist[dest_node][dest_mask] = dest_time;
            pq.push({dest_time,{dest_node,dest_mask}});
          }
        }
      }
      int min_time = INF;
      int target = (1<<k) - 1;
      for(int i =0; i < 1024 ;i++){
        for(int j = 0; j < 1024; j++){
          int val = i | j;
          if(val != target)
            continue;
          min_time = min(min_time,max(dist[n-1][i],dist[n-1][j]));
        }
      }
      cout<<min_time<<endl;
}
