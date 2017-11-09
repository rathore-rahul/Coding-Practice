#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1E9+7;

int main() {
    string s;
    cin>>s;
    long long ans = s[0] - '0';
    long long prev = s[0] - '0';
    for(int i = 1; i < s.length() ;i++){
        prev = ((10*prev)%mod + ((i+1)*(s[i]-'0'))%mod)%mod;
        ans = (ans + prev)%mod;
    }
    cout<<ans<<endl;
}
