#include <bits/stdc++.h>
using namespace std;

#define repi(i,j,n) for(int i = j; i < n ;i++)

int main() {
    std::ios::sync_with_stdio(false);
    long long int n;
    cin>>n;
    set<long long int> st;
    long long int min_loss = 1E17;
    repi(i,0,n){
        long long int temp;
        cin>>temp;
        auto it = st.upper_bound(temp);
        if(it != st.end()){
            min_loss = min(min_loss,*it-temp);
        }
        st.insert(temp);
    }
    cout<<min_loss<<endl;
}
