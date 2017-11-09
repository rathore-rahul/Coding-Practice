#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0; i < n ;i++)
typedef pair<int,int> pi;

int main() {
    int n,m,u,v,c,s,t;
    cin>>n>>m;
    vector<pi> edges[n];
    rep(i,m){
        cin>>u>>v>>c;
        u--;v--;
        edges[u].push_back({v,c});
        edges[v].push_back({u,c});
    }
    cin>>s>>t;
    s--;t--;
    vector<vector<bool> > exist(n,vector<bool> (1024,false));
    queue<pi> pq;
    pq.push({s,0});
    exist[s][0] = true;
    while(!pq.empty()){
        pi temp = pq.front();
        pq.pop();
        int ver = temp.first;
        int val = temp.second;
        for(auto it : edges[ver]){
            int next_ver = it.first;
            int next_val = val | it.second;
            if(!exist[next_ver][next_val]){
                pq.push({next_ver,next_val});
                exist[next_ver][next_val] = true;
            }
        }
    }
    for(int i =0 ;i < 1024 ; i++){
        if(exist[t][i] == true){ cout<<i<<endl; return 0;}
    }
    cout<<"-1\n";
}
