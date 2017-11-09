#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(x) x.rbegin(),x.rend()
#define repi(i,j,n) for(int i = j; i < n ;i++)

int main() {
    int n;
    cin>>n;
    vector<long long int> sides(n);
    repi(i,0,n){
        cin>>sides[i];
    }
    sort(all(sides));
    bool flag = false;
    repi(i,0,n-2){
        if(sides[i+1]+sides[i+2] > sides[i]){
            printf("%lld %lld %lld\n",sides[i+2],sides[i+1],sides[i]);
            flag = true;
            break;
        }
    }
    if(!flag){
        cout<<"-1\n";
    }
}
