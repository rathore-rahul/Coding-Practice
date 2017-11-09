#include<bits/stdc++.h>
using namespace std;

int dp[10][10];

void binomial(int n, int k){
  for(int i = 1; i <= n ; i++){
    for(int k = 0; k <= i ; k++){
      if( k == 0 || k == i){
        dp[i][k] = 1;
        continue;
      }
      dp[i][k] = dp[i-1][k-1] + dp[i-1][k];
    }
  }
}

int main(){
  int n = 6, k = 3;
  binomial(n,k);
  cout<<dp[n][k]<<endl;
}
