#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    stack<pair<int,int> > st;
    long long ans = 0;
    st.push({0,-1});
    for(int i =0; i <= n ;i++){
        int temp;
        if(i != n)
        cin>>temp;
        else temp = 0;
        if(temp >= st.top().first){
            st.push({temp,i});
        }
        else{
            while(st.top().first > temp){
                pair<int,int> tp = st.top();
                st.pop();
                int left = tp.second - st.top().second;
                int right = i - tp.second - 1;
                long long height = tp.first;
                ans = max((left+right)*height,ans);
            }
            st.push({temp,i});
        }
    }
    cout<<ans<<endl;
}
