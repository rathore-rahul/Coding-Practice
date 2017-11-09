#include<bits/stdc++.h>
using namespace std;

int dp[10][100];

int knapSack(int W, int wt[], int val[], int n){
    if( n < 0 || W <= 0)
      return 0;
    if(wt[n] > W)
      return knapSack(W,wt,val,n-1);
    else return max(val[n] + knapSack(W-wt[n],wt,val,n-1),knapSack(W,wt,val,n-1));
}

int dpknapSack(int W, int wt[], int val[], int n){
    for(int i = 0; i <= n ; i++){
      for(int j = 0; j <= W ; j++){
        if(i == 0 || j == 0)
          dp[i][j] = 0;
        else if( j < wt[i-1])
            dp[i][j] = dp[i-1][j];
        else
          dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
      }
    }
    return dp[n][W];
}

int main(){
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int  W = 50;
  int n = sizeof(val)/sizeof(val[0]);
  printf("%d\n", knapSack(W, wt, val, n-1));
  printf("%d\n", dpknapSack(W, wt, val, n));
  return 0;
}
