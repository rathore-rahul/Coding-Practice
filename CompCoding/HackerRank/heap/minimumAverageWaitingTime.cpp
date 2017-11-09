#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<pair<int,int> > atime(n);
    for(int i =0; i < n ;i++){
        cin>>atime[i].first>>atime[i].second;
    }
    sort(atime.begin(),atime.end());
    long long current_time = -1;
    long long waiting_time =0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    int i =0;
    while(i < n ){
        if(pq.empty() && current_time < atime[i].first){
            current_time = atime[i].first;
        }
        while( i < n && atime[i].first <= current_time){
            pq.push({atime[i].second,atime[i].first});
            i++;
        }
        if(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            current_time += temp.first;
            waiting_time += (current_time - temp.second);
        }
    }
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        current_time += temp.first;
        waiting_time += current_time - temp.second;
    }
    cout<< waiting_time/n<<endl;
}
