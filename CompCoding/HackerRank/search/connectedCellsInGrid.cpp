#include <bits/stdc++.h>
using namespace std;

#define repi(i,a,b) for(int i = a; i < b ;i++)
int grid[15][15];
int n,m;
int visited[15][15];
bool isvalid(int x,int y){
    return (x >= 0 && y >= 0 && x < n && y < m && visited[x][y] == 0 && grid[x][y] == 1);
}

int main() {
    cin>>n>>m;
    repi(i,0,n){
        repi(j,0,m){
            cin>>grid[i][j];
        }
    }
    vector<pair<int,int> > nbr;
    repi(i,-1,2){
        repi(j,-1,2){
            if(i == 0 && j == 0)
                continue;
            nbr.push_back(make_pair(i,j));
        }
    }
    memset(visited,0,sizeof(visited[0][0]*n*m));
    int largest = 0;
    repi(i,0,n){
        repi(j,0,m){
            if(visited[i][j] == 0 && grid[i][j] == 1){
                cerr<<" from "<<i<<" "<<j<<"\n";
                int temp_largest = 1;
                visited[i][j] = 1;
                stack<pair<int,int> > st;
                st.push(make_pair(i,j));
                while(!st.empty()){
                    pair<int,int> temp = st.top();
                    st.pop();
                    for(auto it = nbr.begin(); it != nbr.end(); it++){
                        int x = temp.first+it->first;
                        int y = temp.second+it->second;
                        if(isvalid(x,y)){
                            visited[x][y] = 1;
                            temp_largest++;
                            st.push(make_pair(x,y));
                           cerr<<" i, j "<<x<<" "<<y<<"\n";
                        }
                    }
                }
                largest = max(largest,temp_largest);
            }
        }
    }
    cout<<largest<<endl;
}
