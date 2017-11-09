#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int pal[100][100];

int minPalPartion(char* str){
  int n = strlen(str);
  for(int i =0; i < n; i++){
    pal[i][i] = 1;
  }
  for(int L = 2 ; L <= n; L++){
    for(int i = 0 ; i <= n-L ; i++){
      int j = i+L-1;
      dp[i][j] = L-1;
      if(str[i] == str[j] && (L == 2 || pal[i+1][j-1])){
        dp[i][j] = 0;
        pal[i][j] = 1;
      }
      else{
        for(int k = i ; k < j; k++){
          dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
        }
      }
    }
  }
  return dp[0][n-1];
}

int opti_minPalPartion(char *str){
  int n = strlen(str);
  for(int i =0; i < n ;i++){
    pal[i][i] = 1;
  }
  for(int L = 2 ; L <= n ; L++){
    for(int i = 0; i <= n-L; i++){
      int j = i+L-1;
      if(str[i] == str[j] && (L == 2 || pal[i+1][j-1]))
        pal[i][j] = 1;
    }
  }
  vector<int> cut(n);
  for(int i =0; i < n ; i++){
    if(pal[0][i]) cut[i] = 0;
    else{
      int max_cut = i;
      for(int j = 0; j < i ;j++){
        if(pal[j+1][i])
          max_cut = min(max_cut,cut[j]+1);
      }
      cut[i] = max_cut;
    }
  }
  return cut[n-1];
}

int main()
{
   char str[] = "ababbbabbababa";
   //printf("Min cuts needed for Palindrome Partitioning is %d", minPalPartion(str));
   printf("Min cuts needed for Palindrome Partitioning is %d", opti_minPalPartion(str));
   return 0;
}
