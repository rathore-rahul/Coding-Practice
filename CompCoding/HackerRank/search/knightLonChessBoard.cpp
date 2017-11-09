#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n ; i++)
#define repi(i,a,n) for(int i = a; i < n ; i++)
#define mp(a,b) make_pair(a,b)

int grid[30][30];
int ans[30][30];
int weight[30][30];
int n;

bool isvalid(int x,int y){
    return ( x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0);
}

int main() {
    cin>>n;
    memset(ans,-1,sizeof(ans));
    repi(i,1,n){
        repi(j,i,n){
           memset(grid,0,sizeof(grid));
           memset(weight,0,sizeof(weight));
           queue<pair<int,int> > st;
           st.push(mp(0,0));
           grid[0][0] = 1;
           weight[0][0] = 0;
           while(!st.empty()){
               pair<int,int> temp = st.front();
               st.pop();
               int x = temp.first,y=temp.second;
               if(x == n-1 && y == n-1)
               {
                   ans[j][i] = ans[i][j] = weight[x][y];
                   break;
               }
               int w = weight[x][y];
               if(isvalid(x+i,y+j)){
                   weight[x+i][y+j] = w+1;
                   st.push(mp(x+i,y+j));
                   grid[x+i][y+j] = 1;
               }

               if(isvalid(x-i,y+j)){
                   weight[x-i][y+j] = w+1;
                   st.push(mp(x-i,y+j));
                   grid[x-i][y+j] = 1;
               }

               if(isvalid(x+i,y-j)){
                   weight[x+i][y-j] = w+1;
                   st.push(mp(x+i,y-j));
                   grid[x+i][y-j] = 1;
               }

               if(isvalid(x-i,y-j)){
                   weight[x-i][y-j] = w+1;
                   st.push(mp(x-i,y-j));
                   grid[x-i][y-j] = 1;
               }

               if(isvalid(x+j,y+i)){
                   weight[x+j][y+i] = w+1;
                   st.push(mp(x+j,y+i));
                   grid[x+j][y+i] = 1;
               }

               if(isvalid(x-j,y+i)){
                   weight[x-j][y+i] = w+1;
                   st.push(mp(x-j,y+i));
                   grid[x-j][y+i] = 1;
               }

               if(isvalid(x-j,y-i)){
                   weight[x-j][y-i] = w+1;
                   st.push(mp(x-j,y-i));
                   grid[x-j][y-i] = 1;
               }

               if(isvalid(x+j,y-i)){
                   weight[x+j][y-i] = w+1;
                   st.push(mp(x+j,y-i));
                   grid[x+j][y-i] = 1;
               }
           }
        }
    }
    repi(i,1,n){
        repi(j,1,n){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
