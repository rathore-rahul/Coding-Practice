#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i =0; i < n ;i++)
#define allr(x) x.rbegin(),x.rend()

int main() {
    string s;
    vector<int> dict(26,0);
    cin>>s;
    rep(i,s.length()){
        dict[s[i]-'a']++;
    }
    bool flag = false;
    set<int> st;
    rep(i,26){ if(dict[i] != 0){ st.insert(dict[i]);}}
    if(st.size() == 1)
    {cout<<"YES\n";return 0;}
    rep(i,26){
        if(dict[i] == 0)
            continue;
        else{
            st.clear();
            dict[i]--;
            rep(j,26){
                if(dict[j] != 0){ st.insert(dict[j]);}
            }
            if(st.size() == 1){ flag = true;break;}
            dict[i]++;
        }
    }
    if(flag){cout<<"YES\n";}
    else{cout<<"NO\n";}
}
