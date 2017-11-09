#include <bits/stdc++.h>
using namespace std;
const int max_size = 1E7;
int arr[max_size];
int dp[max_size];
int n;

void lis(){
  memset(dp,-1,sizeof(dp));
  for(int i = 1 ;i < n ; i++){
    int max_len = -1;
    for(int j = 0; j < i ; j++){
      if(arr[j] < arr[i]){
        max_len = min(max_len,dp[j]-1);
      }
    }
    dp[i] = max_len;
  }
}

int main(){
  cin>>n;
  for(int i =0; i < n ;i++){
    cin>>arr[i];
  }
  lis();
  cout<<(-dp[n-1])<<endl;
}
