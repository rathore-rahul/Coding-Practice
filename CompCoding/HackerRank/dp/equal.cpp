#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main() {
    int t,n,temp;
    cin>>t;
    for(int i =0; i <= 10000 ;i++){
        int x = 0, y= i;
        x += y/5;
        y = y%5;
        x += y/2;
        y = y%2;
        x += y;
        dp[i] = x;
        
    }
    while(t--){
        cin>>n;
        vector<int> choc;
        int min_choc = 1E9;
        for(int i =0; i<n; i++){
            cin>>temp;
            choc.push_back(temp);
            min_choc = min(min_choc,temp);
        }
        
        int ans = 1E9;
        for(int i =0 ; i < 5 ;i++){
            int temp_ans = 0;
            for(int j = 0 ; j < n; j++){
                temp_ans += dp[choc[j] - (min_choc - i)];       
            }
            ans = min(ans,temp_ans);
        }
        cout<<ans<<endl;
    }
}
