#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,temp;
    cin>>n;
    long long int paths = 0;
    stack<int> towers;
    vector<int> heights(n);
    for(int i = 0 ; i < n; i++){
        cin>>heights[i];
    }
    for(int i =0; i < n ; i){
        if(towers.empty() || towers.top() >= heights[i]){
            towers.push(heights[i]);
            i++;
        }
        else{
            int val = towers.top();
            int counter = 0;
            while(!towers.empty() && towers.top() == val){
                counter++;
                towers.pop();
            }
            paths += counter*1LL*(counter-1);
        }
    }
    while(!towers.empty()){
        int val = towers.top();
        int counter = 0;
        while(!towers.empty() && towers.top() == val){
             counter++;
             towers.pop();
        }
        paths += counter*1LL*(counter-1);
    }
    cout<<paths<<endl;
}
