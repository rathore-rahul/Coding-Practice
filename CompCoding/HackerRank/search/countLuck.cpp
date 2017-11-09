#include <bits/stdc++.h>
using namespace std;

#define repi(i,a,b) for(int i =a; i <b ;i++)
#define mp3(a,b,c) make_pair(a,make_pair(b,c))
#define mp(a,b) make_pair(a,b)
#define F first
#define SF second.first
#define SS second.second
typedef pair<int,pair<int,int> > ppi;

char grid[101][101];
int visited[101][101];
int t,n,m,k,sx,sy,fx,fy;
bool isvalid(int x,int y){
    return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 'X' && visited[x][y] == 0);
}

int main() {
    vector<pair<int,int> > nbr;
    for(int i = -1 ; i <=1 ; i++){
        for(int j = -1; j <=1 ;j++){
            if(i*j == 0 && !(i == 0 && j == 0))
            {nbr.push_back(mp(i,j));}
        }
    }
    cin>>t;
    while(t--){
        memset(grid,0,sizeof(grid[0][0])*101*101);
        memset(visited,0,sizeof(visited[0][0])*101*101);
        cin>>n>>m;
        repi(i,0,n){
            repi(j,0,m){
                cin>>grid[i][j];
                if(grid[i][j] == 'M'){
                    sx = i;sy = j;
                }
                else if(grid[i][j] == '*')
                {
                    fx = i; fy = j;
                }
            }
        }
        cin>>k;

        priority_queue<ppi,vector<ppi> ,greater<ppi> > pq;
        pq.push(mp3(0,sx,sy));
        //cerr<<"start\n";
        visited[sx][sy] = 1;
        while(!pq.empty()){
            ppi temp = pq.top();
            pq.pop();
            int w = temp.F, x = temp.SF , y = temp.SS;
            //cerr<<"top = "<<x<<" "<<y<<"\n";
            if(x == fx && y == fy){
                if(w == k)
                    cout<<"Impressed\n";
                else
                    cout<<"Oops!\n";
                break;
            }
            int counter = 0;
            for(auto it = nbr.begin(); it != nbr.end(); it++){
                if(isvalid(x+it->first,y+it->second))
                    counter++;
            }
            counter = counter > 1 ? 1:0;
            for(auto it = nbr.begin(); it != nbr.end(); it++){

                if(isvalid(x+it->first,y+it->second))
                {
                    pq.push(mp3(w+counter,x+it->first,y+it->second));
                    visited[x+it->first][y+it->second] = 1;
                }
            }

        }
    }
}
