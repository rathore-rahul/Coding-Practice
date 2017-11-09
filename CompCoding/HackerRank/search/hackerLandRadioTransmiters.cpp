#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
    int n,k;
    map<int,bool> pq;
    cin>>n>>k;
    vector<int> vec;
    rep(i,n){
        int x;
        cin>>x;
        if(pq[x] == 1)
            continue;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    int cnt = 0,left = 0;
    while(left < n){
        int lim = vec[left]+k;
        cnt++;
        int mid = upper_bound(vec.begin()+left,vec.end(),lim) - vec.begin();
        if(mid == n)
            break;
        mid--;
        lim = vec[mid]+k;
        int right = upper_bound(vec.begin()+mid,vec.end(),lim) - vec.begin();
        left = right;
    }
    cout<<cnt<<endl;
}
