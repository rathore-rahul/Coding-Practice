#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i =0; i < n ;i++)

int main() {
    int n,m;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    cin>>m;
    vector<int> b(m);
    rep(i,m){
    cin>>b[i];}
    int min_val = 1E5;
    rep(i,m){
        if(b[i] < min_val)
            min_val = b[i];
    }
    vector<int> counters(101);
    rep(i,m){
        counters[b[i]-min_val]++;
    }
    rep(i,n){
        counters[a[i]-min_val]--;
    }
    rep(i,101){
        if(counters[i] > 0)
            cout<<(min_val+i)<<" ";
    }
    cout<<endl;
}
