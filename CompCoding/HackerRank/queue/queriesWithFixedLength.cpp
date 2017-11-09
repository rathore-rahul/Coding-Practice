#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


int main() {
    int n,d,q;
    cin>>n>>q;
    vector<int> A(n);
    for(int i =0; i < n ;i++){
        cin>>A[i];
    }
    while(q--){
        cin>>d;
        deque<pair<int,int> > pq;
        int i =0;
        int current_max = -1E9;
        while(i < d){
            while(!pq.empty() && pq.back().first <= A[i])
                pq.pop_back();
            pq.push_back({A[i],i});
            current_max = max(current_max,A[i]);
            i++;
        }
        int global_min = current_max;
        while(i < n){
            while(!pq.empty() && i - pq.front().second >= d){
                pq.pop_front();
            }
            while(!pq.empty() && pq.back().first <= A[i]){
                pq.pop_back();
            }
            pq.push_back({A[i],i});
            current_max = pq.front().first;
            global_min = min(global_min,current_max);
            i++;
        }
        cout<<global_min<<endl;
    }

}
