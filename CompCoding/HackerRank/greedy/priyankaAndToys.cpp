#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i =0; i< n;i++)

int main() {
    int n,num_toys =0;
    cin>>n;
    vector<int> vi(n);
    rep(i,n){cin>>vi[i];}
    
    sort(vi.begin(),vi.end());
    int ans = 0;
    int last_cost = vi[0]-5;
    for(int i =0;i<n ;i++){
        if(vi[i] - last_cost > 4){
            last_cost = vi[i];
            ans++;
        }
    }
    cout<<ans<<endl;
}
