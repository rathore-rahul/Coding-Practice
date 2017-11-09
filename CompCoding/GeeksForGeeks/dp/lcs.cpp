#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int lcs(string s1,string s2){
  for(int i = 1 ; i <= s1.length() ;i++){
    for(int j = 1 ; j <= s2.length(); j++){
      if(s1[i-1] == s2[j-1]){
        dp[i][j] = dp[i-1][j-1]+1;
      }
      else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  string ans;
  int i = s1.length(),j = s2.length();
  while(i > 0 && j > 0){
    if(s1[i-1] == s2[j-1]){
      ans += s1[i-1];
      i--,j--;
    }
    else{
      if(dp[i-1][j] > dp[i][j-1]){
        i--;
      }
      else
        j--;
    }
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  return dp[s1.length()][s2.length()];
}

int main(){
  string s1 = "AGGTAB";
  string s2 = "GXTXAYB";
  cout<<lcs(s1,s2)<<endl;
}
