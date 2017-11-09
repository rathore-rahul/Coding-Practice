#include<bits/stdc++.h>
using namespace std;

int inc[100];
int decr[100];

int lbs(int arr[], int n){
  for(int i =0; i < n ; i++){
    inc[i] = 1;
    for(int j =0; j < i; j++){
      if(arr[j] < arr[i])
        inc[i] = max(inc[i],inc[j]+1);
    }
  }
  for( int i = n-1 ; i >= 0 ;i--){
    decr[i] = 1;
    for(int j = i+1 ; j < n ; j++){
      if(arr[j] < arr[i])
        decr[i] = max(decr[i],decr[j]+1);
    }
  }
  int gmax = 1;
  for(int i =0; i < n ;i++){
    gmax = max(gmax,inc[i]+decr[i]);
  }
  return gmax -1 ;
}

int main()
{
  int arr[] = {80, 60, 30, 40, 20, 10};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LBS is %d\n", lbs( arr, n ) );
  return 0;
}
