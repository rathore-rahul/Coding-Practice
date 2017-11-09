#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i =0;i<n;i++)
#define all(x) x.begin(),x.end()

int main() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        cin>>b[i];
    }
    int bin_a = 0,bin_b =0;
    sort(all(a));sort(all(b));
    int i = 0,j =0,beautiful_pairs = 0;
    while(i < n && j < n){
        if(a[i] == b[j]){ beautiful_pairs++;i++;j++;}
        else if(a[i] > b[j]){j++;bin_b++;}
        else{i++;bin_a++;}
    }
    if(bin_a == 0 && bin_b == 0)
        beautiful_pairs--;
    else
        beautiful_pairs++;
    cout<<beautiful_pairs<<endl;
}
