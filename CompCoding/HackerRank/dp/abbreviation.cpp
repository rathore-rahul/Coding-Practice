#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
    int q;
    cin>>q;
    while(q--){
        memset(dp,0,sizeof(dp[0][0])*1001*1001);
        string a,b;
        cin>>a>>b;
        dp[0][0] = 1;
        for(int i = 1; i <= a.length();i++){
            if(a[i-1] > 'Z'){
                dp[i][0] = 1;
            }
            else break;
        }
        for(int i = 1; i <= a.length();i++){
            for(int j = 1; j <= b.length(); j++){
                if(islower(a[i-1])){
                    if((toupper(a[i-1]) == b[j-1] && dp[i-1][j-1] == 1) || dp[i-1][j] == 1)
                        dp[i][j] = 1;;
                }
                else if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        if(dp[a.length()][b.length()] == 1)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}
