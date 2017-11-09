#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i =0 ; i < n ;i++)

int main() {
    int n,k,temp;
    cin>>n>>k;
    std::priority_queue<int, std::vector<int>, std::greater<int> > hp;
    rep(i,n){
        cin>>temp;
        hp.push(temp);
    }
    int operations = 0;
    while(!hp.empty() && hp.top() < k){
        int t1 = hp.top();
        hp.pop();
        if(hp.empty())
            break;
        int t2 = hp.top();
        hp.pop();
        hp.push(t1+2*t2);
        operations++;
    }

    if(hp.empty())
        cout<<-1;
    else
        cout<<operations;
}
