#include <bits/stdc++.h>

using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    vector<int> prev(n);
    int last_found = -1;
    for(int i = 0 ; i < n ;i++){
        int temp;
        cin>>temp;
        if(temp == 1) last_found = i;
        prev[i] = last_found;
    }
    int ans = 0;
    for(int i =0; i < n;){
        int pos = prev[min(i+k-1,n-1)];
        if(pos == -1 || pos + k <= i){
            cout<<"-1\n";
            return 0;
        }
        ans += 1;
        i = pos + k;
    }
    cout<<ans<<endl;
}
