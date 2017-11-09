#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i =0; i < n ; i++)

bool overlap(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second >= b.first)
        return true;
    else
        return false;
}

pair<int,int> mergeInterval(const pair<int,int> & a, const pair<int,int> &b){
    return make_pair(a.first,max(a.second,b.second));
}

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,pair<int,int> > > tracks(k);
    rep(i,k){
        int r,c1,c2;
        cin>>r>>c1>>c2;
        tracks[i].first = r;
        tracks[i].second.first = c1;
        tracks[i].second.second = c2;
    }
    sort(tracks.begin(),tracks.end());
    long long counter = 0;
    for(int i =0; i < k ;i++){
        int r = tracks[i].first;
        pair<int,int> start = tracks[i].second;
        //cerr<<" new start = "<<start.first<<" "<<start.second<<"\n";
        while( i < k && tracks[i].first == r){
            pair<int,int> interval = tracks[i].second;
            //cerr<<" interval to check "<< interval.first<<" "<<interval.second<<"\n";
            if(overlap(start,interval)){
                //cerr<<" overlap \n";
                start = mergeInterval(start,interval);
            }
            else{
               // cerr<<"non overlap\n";
                counter += start.second - start.first + 1;
                start = interval;
            }
            //cerr<<"start = "<<start.first<<" "<<start.second<<"\n";
            i++;
        }
        counter += start.second - start.first + 1;
        if(i != k)
            i--;
    }
    long long pro = n;
    pro *= m;
    pro -= counter;
    cout<<pro<<endl;
}
