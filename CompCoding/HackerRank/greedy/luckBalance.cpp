#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i< n; i++)

bool compare(const pair<int,int> &left,const pair<int,int> &right){
    if(left.first > right.first)
        return true;
    else if(left.first == right.first && left.second <= right.second)
        return true;
    else 
        return false;
        
}

int main() {
    int n,k,imp_contest=0,a,b;
    cin>>n>>k;
    vector<pair<int,int> > vp(n);
    rep(i,n){
        cin>>a>>b;
        if(b==1)
            imp_contest++;
        vp[i] = make_pair(b,a); 
    }
    sort(vp.begin(),vp.end(),compare);
    int min_win = imp_contest-k;
    int luck = 0;
    rep(i,min_win)
        luck -= vp[i].second;
    for(int i = min_win ; i < n ;i++)
        luck += vp[i].second;
    cout<<luck<<endl;
}
