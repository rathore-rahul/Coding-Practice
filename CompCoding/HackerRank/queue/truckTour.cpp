#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<long long int> petrol(n);
    vector<long long int> dist(n);
    for(int i =0; i < n ; i++){
        cin>>petrol[i];
        cin>>dist[i];
    }
    queue<int> pq;
    long long cum_sum = 0;
    int i =0;
    while(pq.size() < n){
        pq.push(i);
        cum_sum += petrol[i];
        cum_sum -= dist[i];
        while(cum_sum < 0 && !pq.empty()){
            int ti = pq.front();
            pq.pop();
            cum_sum += dist[ti];
            cum_sum -= petrol[ti];
        }
        i = (i+1)%n;
    }
    cout<<pq.front()<<endl;
}
