#include <bits/stdc++.h>
using namespace std;

int getSum(int BITree[], int index){
  index = index + 1;
  int sum = 0;
  while(index > 0){
    sum += BITree[index];
    index -= index & (-index);
  }
  return sum;
}

void updateBIT(int BITree[], int n, int index , int diff){
  index = index + 1;
  while(index <= n){
    BITree[index] += diff;
    index += index & (-index);
  }
}

int * constructBITree(int arr[], int n){
  int *BITree = new int[n+1];
  memset(BITree, 0, sizeof(BITree));
  for(int i = 0; i < n; i++){
    updateBIT(BITree, n, i, arr[i]);
  }
  return BITree;
}

int main(){
  int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(freq)/sizeof(freq[0]);
  int *BITree = constructBITree(freq, n);
  cout << "Sum of elements in arr[0..5] is "
       << getSum(BITree, 5);

  // Let use test the update operation
  freq[3] += 6;
  updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[]

  cout << "\nSum of elements in arr[0..5] after update is "
       << getSum(BITree, 5)<<"\n";

  return 0;
}
