#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0; i < n ; i++)
#define repi(i,j,n) for(int i =j; i < n ; i++)


unsigned long long myHash(vector<int> freq)
{
    unsigned long long t=1,ret=0;
    for(int i=0; i<26; i++)
    {
        ret += t*freq[i];
        t=t*(unsigned long long)1000003;
    }
    return ret;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        map<unsigned long long,int> mp;
        string s;
        cin>>s;
        rep(i,s.length()){
            vector<int> freq(26);
            repi(j,i,s.length()){
                freq[s[j]-'a']++;
                mp[myHash(freq)]++;
            }
        }
        long long ans = 0;
        for(auto it = mp.begin(); it != mp.end() ;it++){
            int val = it->second;
            ans += (val*(val-1))/2;
        }
        cout<<ans<<endl;
    }
}
