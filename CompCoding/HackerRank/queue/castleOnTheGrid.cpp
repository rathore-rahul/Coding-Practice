#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

char grid[200][200];
int visited[200][200];

int main() {
    int n;
    cin>>n;
    for(int i =0; i < n ;i++){
        for(int j =0; j < n ;j++){
            cin>>grid[i][j];
        }
    }
    memset(visited,0,sizeof(visited));
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    queue<pair<int,pair<int,int> > > pq;
    if(a == c && b == d)
        cout<<"0\n";
    else{
        pq.push(mp(0,mp(a,b)));
        visited[a][b] = 1;
        while(!pq.empty()){
            pair<int,pair<int,int> > temp = pq.front();
            pq.pop();
            int x = temp.second.first, y = temp.second.second;
            if(x == c && y == d)
            {
                cout<<temp.first<<"\n";
                break;
            }
            for(int i = x+1; i < n ;i++){
                if(grid[i][y] == 'X')
                    break;
                if(visited[i][y] == 0){
                    pq.push(mp(temp.first+1,mp(i,y)));
                    visited[i][y] = 1;
                }
            }
            for(int i = x-1; i >= 0 ;i--){
                if(grid[i][y] == 'X')
                    break;
                if(visited[i][y] == 0){
                    pq.push(mp(temp.first+1,mp(i,y)));
                    visited[i][y] = 1;
                }
            }
            for(int i = y+1; i < n ;i++){
                if(grid[x][i] == 'X')
                    break;
                if(visited[x][i] == 0){
                    pq.push(mp(temp.first+1,mp(x,i)));
                    visited[x][i] = 1;
                }
            }
            for(int i = y-1; i >= 0 ;i--){
                if(grid[x][i] == 'X')
                    break;
                if(visited[x][i] == 0){
                    pq.push(mp(temp.first+1,mp(x,i)));
                    visited[x][i] = 1;
                }
            }
        }
    }
}
