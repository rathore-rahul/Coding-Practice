#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int rec_cut(int arr[],int len, int index){
  if(len < 0)
    return -1E9;
  if(index  < 0)
    return 0;
  if(index + 1 <= len){
    return max(rec_cut(arr,len,index-1),rec_cut(arr,len-index-1,index) + arr[index]);
  }
  else
    return rec_cut(arr,len,index-1);
}

int cutRod(int arr[], int len){
  for(int i = 1 ; i <= len ; i++){
    for(int j = 1; j <= len ; j++){
      if(j < i)
        dp[i][j] = dp[i-1][j];
      else
      dp[i][j] = max(dp[i][j-i]+arr[i-1],dp[i-1][j]);
    }
  }
    return dp[len][len];
}


int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    printf("Maximum Obtainable Value is %d\n", rec_cut(arr, size,size-1));
    getchar();
    return 0;
}
