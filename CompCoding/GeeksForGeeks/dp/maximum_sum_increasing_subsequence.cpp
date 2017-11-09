#include<bits/stdc++.h>
using namespace std;

int dp[100];

int maxSumIS(int arr[], int n){
  int global_max = -1E9;
  for(int i = 0; i < n ; i++){
    dp[i] = arr[i];
    for(int j =0 ; j < i ; j++){
      if(arr[j] < arr[i]){
        dp[i] = max(arr[i]+dp[j],dp[i]);
        global_max = max(global_max,dp[i]);
      }
    }
  }
  return global_max;
}

int rec_max_sum(int arr[],int index){
  int max_val = -1E9;
  bool flag = true;
  for(int i = 0; i < index ; i++){
    if(arr[i] < arr[index]){
      max_val = max(max_val,rec_max_sum(arr,i)+arr[index]);
      flag = false;
    }
  }
  if(flag)
    max_val = arr[index];
  return max_val;
}

int rec_helper(int arr[], int n){
  int max_val = -1E9;
  for(int i = 0; i <= n ; i++){
      if(arr[i] > arr[n]){
        max_val = max(max_val,rec_max_sum(arr,i));
      }
  }
  return max_val;
}

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Sum of maximum sum increasing subsequence is %dn",
           maxSumIS( arr, n ) );
    printf("%d\n",rec_helper(arr,n-1));
    return 0;
}
