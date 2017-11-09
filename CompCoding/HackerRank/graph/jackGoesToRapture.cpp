#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i =0; i < n ;i++)

const int max_nodes = 5*(1E4)+1;
vector<pair<int,int> > edges[max_nodes];
const int INF = 1E9;
typedef pair<int,int> pi;

int main() {
    int n,e;
    cin>>n>>e;
    rep(i,e){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    vector<int> key(n,INF);
    vector<bool> visited(n,false);
    priority_queue<pi,vector<pi>, greater<pi> > pq;
    pq.push({0,0});
    key[0] = 0;
    while(!pq.empty()){
        pi temp = pq.top();
        pq.pop();
        int w = temp.first;
        int u = temp.second;
        if( u == n-1){
           cout<<w<<endl;
           return 0;
        }
        visited[u] = true;
        for(auto it : edges[u]){
            int v = it.first;
            int ew = it.second;
            if(!visited[v]){
                if(ew <= w && key[v] > w){
                    pq.push({w,v});
                    key[v] = w;
                }
                else if(ew > w && key[v] > ew){
                    pq.push({ew,v});
                    key[v] = ew;
                }
                
            }
        }
    }
    cout<<"NO PATH EXISTS"<<endl;
    
}
