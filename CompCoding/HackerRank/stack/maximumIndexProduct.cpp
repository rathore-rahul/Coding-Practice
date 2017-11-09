#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,temp;
    cin>>n;
    vector<int> left(n+1);
    vector<int> right(n+1);
    vector<int> vals(n);
    stack<pair<int,int> > st;
    for(int i =0; i < n ; i++){
        cin>>vals[i];
    }
    for(int i = 1 ; i <= n ; i){
        temp = vals[i-1];
        if(st.empty() || temp <= st.top().first){
            st.push(make_pair(temp,i));
            i++;
        }
        else{
            while(!st.empty() && st.top().first < temp){
                pair<int,int> t = st.top();
                st.pop();
                right[t.second] = i;
            }
        }
    }
    stack<pair<int,int> > temper;
    st.swap(temper);
    reverse(vals.begin(),vals.end());
    for(int i = 1 ; i <= n ; i){
        temp = vals[i-1];
        if(st.empty() || temp <= st.top().first){
            st.push(make_pair(temp,i));
            i++;
        }
        else{
            while(!st.empty() && st.top().first < temp){
                pair<int,int> t = st.top();
                st.pop();
                left[n+1-t.second] = (n+1)-i;
            }
        }
    }

    long long int max_val = 0LL;
    for(int i =1 ; i <= n ;i++){
        max_val = max(max_val,left[i]*1LL*right[i]);
    }
    cout<<max_val<<endl;
}
