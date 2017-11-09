#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int min_cost(int p[], int n){
  for(int L = 2; L <= n ;L++){
    for(int i = 0 ; i <= n-L ;i++){
      int j = i + L - 1;
      dp[i][j] = 1E9;
      for(int k = i; k < j ; k++){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j+1]);
      }
    }
  }
  return dp[0][n-1];
}
int main(){
  int p[5] = {35,15,5,10,20};
  int cost = min_cost(p,4);
  cout<<cost<<endl;
}
