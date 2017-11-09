#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    vector<int> vals(n+1);
    vector<int> pos(n+1);
    for(int i =1; i <= n ;i++){
        cin>>vals[i];
        pos[vals[i]] = i;
    }
    int num_swaps = 0;
    for(int i =1; i <= n && num_swaps < k;i++){
        if(vals[i] != n+1-i){
            num_swaps++;
            int temp = vals[i];
            swap(pos[n+1-i],pos[vals[i]]);
            swap(vals[pos[n+1-i]],vals[pos[temp]]);
        }
    }
    for(int i =1; i <= n ;i++){
        cout<<vals[i]<<" ";
    }
    cout<<endl;
}
