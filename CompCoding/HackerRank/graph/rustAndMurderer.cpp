#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> color(n+1);  // 0 white 1 grey 2 black
        vector<vector<int> > edges(n+1);
        vector<int> dist(n+1);
        for(int i =0;i < m; i++){
            int x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        int s;
        cin>>s;
        queue<int> pq;
        pq.push(s);
        color[s] = 1;
        dist[s] = 0;
        set<int> l1,l2;
        for(int i = 1 ; i <= n ;i++){
            if(i != s)
                l1.insert(i);
        }
        while(!pq.empty()){
            int u = pq.front();
            pq.pop();
            for(auto it : edges[u]){
                if(color[it] == 0){
                    l2.insert(it);
                    l1.erase(it);
                }
            }
            for(auto it : l1){
                color[it] = 1;
                dist[it] = dist[u]+1;
                pq.push(it);
            }
            color[u] = 2;
            l1.swap(l2);
            l2.clear();
        }
        for(int i = 1; i <= n ;i++){
            if(i != s){
                cout<<dist[i]<<" ";
            }
        }
        cout<<endl;
    }
}
