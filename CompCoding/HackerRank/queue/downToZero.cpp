#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

const int size = 1E6+1;

int main() {
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        int N;
        cin >> N;
        if(N == 0)
        {cout<<"0\n";continue;}
        vector<bool> visited(N+1,false);
        queue<pair<int,int> > pq;
        pq.push(mp(N,0));
        visited[N] = true;
        while(!pq.empty()){
            pair<int,int> temp = pq.front();
            pq.pop();
            int val = temp.first;
            int steps = temp.second;
            if(val-1 == 0){
              cout<<steps+1<<"\n";
                break;
            }
            if(!visited[val-1])
            {pq.push(mp(val-1,steps+1));visited[val-1] = true;}
            for(int i = 2 ; i*i <= val ;i++){
                if(val % i == 0 && !visited[val/i]){
                    pq.push(mp(val/i,steps+1));
                    visited[val/i] = true;
                }
            }

        }
    }
}
