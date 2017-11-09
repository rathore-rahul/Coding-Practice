#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
  int max_possible = arr[0], next_possible = 0, moves = 1;
  int i = 0;
  while(i < n){
    if(max_possible >= n-1)
      return moves;
    while( i <= max_possible)
    {
      next_possible = max(next_possible,i+arr[i]);
      i++;
    }
    max_possible = next_possible;
    moves++;;
  }
}

int main()
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
    return 0;
}
