#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

bool isSubsetSum(int arr[], int n, int sum){
  if(sum == 0)
    return true;
  if(n == 0)
    return false;
  return isSubsetSum(arr,n-1,sum) || isSubsetSum(arr,n-1,sum-arr[n-1]);
}

bool findPartiion(int arr[], int n){
  int sum = 0;
  for(int i =0; i < n ;i++){
    sum += arr[i];
  }
  if(sum%2 != 0)
    return false;
  return isSubsetSum(arr,n,sum/2);
}

bool existPartition(int arr[],int n){
  int sum = 0;
  for(int i = 0 ; i < n ; i++){
    sum += arr[i];
  }
  if(sum%2 != 0)
    return false;
  sum /= 2;
  for(int i = 0 ; i <= n ; i++){
    dp[i][0] = 1;
  }
  for(int i = 1; i <= n ; i++){
    for(int j = 1; j <= sum ; j++){
      if(j >= arr[i])
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i]]);
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][sum];
}

int main()
{
  int arr[] = {3, 1, 1, 2, 2, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (findPartiion(arr, n) == true)
     printf("Can be divided into two subsets "
            "of equal sum\n");
  else
 printf("Can not be divided into two subsets"
        " of equal sum\n");
        if (existPartition(arr, n) == true)
           printf("Can be divided into two subsets "
                  "of equal sum\n");
        else
           printf("Can not be divided into two subsets"
                  " of equal sum\n");

  return 0;
}
