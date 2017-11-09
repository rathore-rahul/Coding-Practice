#include <bits/stdc++.h>
using namespace std;

const int size = 1E7+1;

int exist[size];

int main() {
    memset(exist,0,sizeof(exist));
    string s;
    cin>>s;
    int q,t;
    cin>>q;
    s = s+'0';
    int counter =0;
    for(int i =0 ;i < s.length()-1 ;i++){
        counter++;
        if(s[i] != s[i+1]){
            int weight = s[i] - 'a' + 1;
            for(int j =1 ; j <= counter ;j++){
                if(j*weight >= size)
                    break;
                exist[j*weight] = 1;
            }
            counter = 0;
        }
    }
    while(q--){
        cin>>t;
        if(exist[t] == 1){
            cout<<"Yes\n";
        }
        else
            cout<<"No\n";
    }
}
