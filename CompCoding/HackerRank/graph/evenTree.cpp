#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> vec[101];
int size[101];
int visited[101];
int dfs(int root){
    visited[root] = 1;
    int st = 1;
    int ans = 0;
    for(int i =0; i < vec[root].size();i++){
        if(visited[vec[root][i]] == 0){
            ans += dfs(vec[root][i]);
            st += size[vec[root][i]];
        }
    }
    size[root] = st;
    if(st%2 == 0 && root != 0)
        ans++;
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i =0; i < m; i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int root = 0;
    int ans = dfs(root);
    cout<<ans<<endl;
}
