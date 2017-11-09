#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int egg_drop(int n, int k){
  if(k == 0 || k == 1 || n == 1)
      return k;

  int min_val = 1E9;
  for(int i = 1 ; i <= k ; i++){
    min_val = min(min_val,1 + max(egg_drop(n-1,i-1),egg_drop(n,k-i) ) );
  }
  return min_val;
}

int dp_egg_drop(int n, int f){
  for(int i = 1; i <= n ; i++){
    for(int j = 0; j <= f ; j++){
      dp[i][j] = 1E9;
      if( j == 0 || j == 1 || i == 1)
        dp[i][j] = j;
      else{
        for(int k = 1; k <= j ; k++){
            dp[i][j] = min(dp[i][j],1 + max(dp[i-1][k-1],dp[i][j-k]));
        }
      }
    }
  }
  return dp[n][f];
}

int main(){
  int n = 2, k = 36;
  // printf ("\nMinimum number of trials in worst case with %d eggs and "
  //          "%d floors is %d \n", n, k, egg_drop(n, k));
  printf ("\nMinimum number of trials in worst case with %d eggs and "
           "%d floors is %d \n", n, k, dp_egg_drop(n, k));
}
