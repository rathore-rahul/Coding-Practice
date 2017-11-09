#include <bits/stdc++.h>
using namespace std;

const int max_nodes = 1E5+1;
vector<pair<int,int> > edges[max_nodes];
typedef pair<int,int> pi;
vector<int> parent(max_nodes);
set<pair<int,int> > child[max_nodes];
const int myrange =2*(1E5)+70;
vector<long long int> counter(myrange+1,0);

int n,m;
int bm = -1;

int dfs(int v,int p){
    int lower_node = 1;
    for(auto it : child[v]){
        if(it.first == p) continue;
        int lower_sub = dfs(it.first,v);
        lower_node += lower_sub;
        bm = max(bm,it.second);
        counter[it.second] += lower_sub*1LL*(n-lower_sub);
    }
    return lower_node;
}


int main() {
    
    cin>>n>>m;
    for(int i =0; i < m ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    priority_queue<pi,vector<pi>,greater<pi> > pq;
    vector<bool> visited(n+1);
    vector<int> key(n+1,1E9);
    pq.push({0,1});
    key[1] = 0;
    parent[1] = 0;
    while(!pq.empty()){
        pi temp = pq.top();
        pq.pop();
        visited[temp.second] = true;
        for(auto it : edges[temp.second]){
            int v = it.first;
            int w = it.second;
            if(!visited[v] && key[v] > w){
                pq.push({w,v});
                int old_parent = parent[v];
                child[old_parent].erase({v,key[v]});
                key[v] = w;
                parent[v] = temp.second;
                child[temp.second].insert({v,key[v]});
            }
        }
    }
    dfs(1,0);
    for(int i =0; i < bm ;i++){
        int rem = counter[i]%2;
        int val = counter[i]/2;
        counter[i+1] += val;
        counter[i] = rem;
    }
    
    while(counter[bm] > 1){
        counter[bm+1] = counter[bm]/2;
        counter[bm] = counter[bm]%2;
        bm++;
    }
    while(bm >= 0){
        char c = ('0'+counter[bm]);
        bm--;
        cout<<c;
    }
    cout<<endl;
}
