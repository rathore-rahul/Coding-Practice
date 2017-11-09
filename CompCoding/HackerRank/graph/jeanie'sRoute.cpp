#include <bits/stdc++.h>
using namespace std;

const int max_nodes = 1E5+1;
vector<pair<int,int> >edges[max_nodes];
vector<bool> isgood(max_nodes);
vector<int> tnode;

int total_path = 0;
int D = 0;

void dfs(int v, int p) {
    for(auto it : edges[v]){
        if(it.first == p) continue;
        dfs(it.first,v);
        isgood[v] = isgood[v]||isgood[it.first];
    }
}

int dfs_dia(int v,int p){
    pair<int,int> half_path;
    for(auto it : edges[v]){
        if(it.first == p || !isgood[it.first]) continue;
        total_path += 2*it.second;
        half_path.first = max(half_path.first, dfs_dia(it.first,v) + it.second);
        if(half_path.first > half_path.second) swap(half_path.first,half_path.second);
    }
    D = max(D,half_path.first + half_path.second);
    return half_path.second;
}

int main() {
    int n,k;
    cin>>n>>k;
    for(int i =0; i < k ;i++){
        int a;
        cin>>a;
        isgood[a] = true;
        tnode.push_back(a);
    }
    for(int i =1; i < n ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    dfs(tnode[0],0);
    int dia = dfs_dia(tnode[0],0);
    cout<<(total_path - D)<<endl;
}
