#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> vals(n);
    vector<int> counts(n);
    for(int i =0; i <n ; i++){
        cin>>vals[i];
        if(vals[i] == 0 || vals[i] >= n)
            continue;
        int j = (i - vals[i] + n)%n;
        counts[(i+1)%n] += 1;
        counts[(j+1)%n] -= 1;
    }
    int max_index = 0,max_val = counts[0];
    int running_sum = counts[0];
    for(int j = 1 ; j < n ; j++){
        running_sum += counts[j];
        if(running_sum > max_val){
            max_val = running_sum;
            max_index = j;
        }
    }
    cout<<(1+max_index)<<"\n";
}
