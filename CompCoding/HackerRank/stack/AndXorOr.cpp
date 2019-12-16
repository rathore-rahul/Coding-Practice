#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int n;
    cin>>n;
    int maxval = 0,temp;
    stack<int> st;
    for(int i =0; i < n ;i++){
        cin>>temp;
        while(!st.empty() && st.top() >= temp){
            maxval = max(maxval,st.top()^temp);
            st.pop();
        }
        if(!st.empty()){
            maxval = max(maxval,st.top()^temp);
        }
        st.push(temp);
    }
    cout<<maxval<<endl;
}
