#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    vector<int> vals(n);
    for(int i =0; i < n ;i++){
        cin>>vals[i];
    }
    sort(vals.begin(),vals.end());
    int max_diff = 1E9;
    for(int i = k-1 ; i < n ;i++){
        int cdiff = vals[i] - vals[i-(k-1)];
        if(cdiff < max_diff)
            max_diff = cdiff;
    }
    cout<<max_diff<<endl;
}
