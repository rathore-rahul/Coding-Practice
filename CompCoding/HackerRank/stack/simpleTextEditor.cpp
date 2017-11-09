#include<bits/stdc++.h>
using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    stack<string> operations;
    string s,w;
    int q,type,k;
    cin >> q;
    while(q--){
        cin>>type;
        switch(type){
            case 1:
                cin>>w;
                operations.push(s);
                s = s+w;
                break;
            case 2:
                cin >> k;
                operations.push(s);
                s = s.erase(s.length()-k);
                break;
            case 3:
                cin>>k;
                cout<<s[k-1]<<"\n";
                break;
            case 4:
                s = operations.top();
                operations.pop();
        }
    }
}
