#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        bool flag = true;
        int t = s.length();
        for(int i = 1 ; i < t ;i++){
            //cout<<abs(s[i] - s[i-1])<<" "<<abs(s[t-1-i] - s[t-1 - (i-1)])<<"\n";
            if(abs(s[i] - s[i-1]) != abs(s[t-1-i] - s[t-1 - (i-1)])){
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<"Funny\n";
        else
            cout<<"Not Funny\n";
    }
}
