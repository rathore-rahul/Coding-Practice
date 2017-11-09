#include <bits/stdc++.h>
using namespace std;

set<pair<int,int> > obstacles;
int n,k;

int moveX[] = {1,1,1,-1,-1,-1,0,0};
int moveY[] = {1,-1,0,1,-1,0,1,-1};

bool isvalid(int x, int y){
    auto it = obstacles.find({x,y});
    return (x <= n && x >= 1 && y <= n && y >= 1 && it == obstacles.end());
}

int main() {
    cin>>n>>k;
    int rq, cq, ro, co;
    cin>>rq>>cq;
    for(int i =0; i < k ;i++){
        cin>>ro>>co;
        obstacles.insert({ro,co});
    }
    int ans = 0;
    int x,y;
    for(int i =0; i < 8 ;i++){
        x = rq, y = cq;
        while(isvalid(x+moveX[i],y+moveY[i])){
            ans++;
            x += moveX[i];
            y += moveY[i];
        }
    }
    cout<<ans<<endl;
}
