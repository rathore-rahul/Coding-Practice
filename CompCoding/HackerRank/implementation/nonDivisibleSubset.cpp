#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int n,k,a;
    cin>>n>>k;
    vector<int> mod(k);
    for(int i =0; i < n ; i++){
        cin>>a;
        mod[a%k]++;
    }
    int max_size = 0;
    if(mod[0])
        max_size += 1;

    for(int i =1; i <= k/2 ;i++){
        if(2*i != k)
            max_size += max(mod[i],mod[k-i]);
        else if(mod[i] > 0)
            max_size += 1;
    }
    cout<<max_size<<endl;
}
