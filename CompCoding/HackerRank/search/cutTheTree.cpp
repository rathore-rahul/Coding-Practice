#include <bits/stdc++.h>
using namespace std;

const int ssize = 1E5+1;
int n;
vector<int> rch[ssize];
int weight[ssize];
int st[ssize];
int visited[ssize];

void dfs(int root){
    int cum_sum = weight[root];
    visited[root] = true;
    for(int i = 0; i < rch[root].size() ;i++){
        if(visited[rch[root][i]] == 0){
            dfs(rch[root][i]);
            cum_sum += st[rch[root][i]];
        }
    }
    st[root] += cum_sum;
}

int main() {
    memset(visited,0,sizeof(visited));
    memset(st,0,sizeof(st));
    vector<pair<int,int> > edges;
    cin>>n;
    int total = 0;
    for(int i =0; i< n; i++){
        cin>>weight[i];
        total += weight[i];
    }
    for(int i =0; i < n-1 ;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        rch[x].push_back(y);
        rch[y].push_back(x);
        edges.push_back(make_pair(x,y));
    }
    int root = 0;
    dfs(root);
    int minval = 2E9;
    for(int i =0; i < edges.size();i++){
        int x = edges[i].first,y = edges[i].second;
        int one_half = min(st[x],st[y]);
        int other_half = total-one_half;
        minval = min(abs(one_half-other_half),minval);
    }
    cout<<minval<<endl;
}
