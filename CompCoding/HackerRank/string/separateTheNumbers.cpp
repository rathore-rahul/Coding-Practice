#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll unsigned long long

ll str_to_ll(string input){
    ll output = 0LL;
    for(int i =0; i < input.length();i++){
        output = output*10 + input[i]-'0';
    }
    return output;
}

bool possible(string s,string prefix){
    if(prefix[0] == '0')
        return false;
    ll val = str_to_ll(prefix);
    int parts = 1;
    while(prefix.length() < s.length()){
        val++;
        prefix += to_string(val);
        parts++;
    }
    if(prefix != s)
        return false;
    if(parts < 2)
        return false;
    return true;
}

pair<bool,ll> generate(string s){
    for(int i =1; i <= 16; i++){
        if(s.length() < i)
            break;
        string temp = s.substr(0,i);
        if(possible(s,temp))
            return make_pair(true,str_to_ll(temp));
    }
    return make_pair(false,0LL);
}

int main() {
   int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        pair<bool,ll> out = generate(s);
        if(out.first)
            cout<<"YES "<<out.second<<"\n";
        else
            cout<<"NO\n";

    }
}
