#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i < n ;i++)

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> val(n);
        rep(i,n){
            cin>>val[i];
            if(i != 0)
                val[i] += val[i-1];
        }
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;
        right[n-1] = 0;
        left[n-1] = val[n-2];
        right[0] = val[n-1] - val[0];
        for(int i = 1; i<n-1 ;i++){
            left[i] = val[i-1];
            right[i] = val[n-1] - val[i];
        }
        bool flag = false;
        rep(i,n){
            if(left[i] == right[i])
            {flag = true; break;}
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
