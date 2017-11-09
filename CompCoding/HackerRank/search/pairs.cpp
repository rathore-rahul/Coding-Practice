#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    vector<long long> vec(n);
    for(int i =0; i < n ;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    long long counter = 0;
    for(int i =0; i < n ;i++){
        int start = lower_bound(vec.begin()+i+1,vec.end(),k+vec[i]) - vec.begin();
        while(start < n && vec[start] == vec[i]+k)
        {counter++;start++;}
    }
    cout<<counter<<endl;
}
