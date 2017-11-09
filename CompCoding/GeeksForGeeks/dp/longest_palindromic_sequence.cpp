#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int rec_lps(char * seq, int i ,int j){
  if(i == j)
    return 1;
  if(i > j)
    return 0;
  if(seq[i] == seq[j])
    return 2 + rec_lps(seq,i+1,j-1);
  return max(rec_lps(seq,i+1,j),rec_lps(seq,i,j-1));
}

int lps(char * seq){
  int n = strlen(seq);
  memset(dp,-1,sizeof(dp[0][0])*100*100);
  for(int L = 2; L <= n ; L++){
    for(int i = 0; i <= n-L ; i++){
      int j = i+L-1;
      if(seq[i] == seq[j])
        dp[i][j] = dp[i+1][j-1] - 2;
      else
        dp[i][j] = min(dp[i+1][j],dp[i][j-1]);
    }
  }
  return -dp[0][n-1];
}

int main()
{
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    printf("The length of the LPS is %d\n", rec_lps(seq,0,n-1));
    printf ("The length of the LPS is %d", lps(seq));
    getchar();
    return 0;
}
