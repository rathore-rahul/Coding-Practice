#include <iostream>
using namespace std;

int partition(int *arr, int low, int high){
  int index = low;
  int pivot = arr[high];
  for(int i =low; i <= high ;i++){
    if(arr[i] <= pivot){
      swap(arr[i],arr[index]);
      index++;
    }
  }
  return index-1;
}

void qsort(int *arr,  int low, int high){
  if(low < high){
    int pivot = partition(arr,low,high);
    qsort(arr,low,pivot-1);
    qsort(arr,pivot+1,high);
  }
}

int main(){
  int n;
  cin>>n;
  int *arr = new int[n];
  for(int i =0; i < n ; i++){
    cin>>arr[i];
  }
  int target;
  cin>>target;
  qsort(arr,0,n-1);
  int count = 0;
  for(int i =0; i < n ; ){
    int left = i+1, right = n-1;
    while(left < right){
      if(arr[i]*arr[left]*arr[right] == target){
        count++;
        while(left < n-1 && arr[left] == arr[left+1])
          left++;
        while(right > 0 && arr[right] == arr[right-1])
          right--;
        left++,right--;
      }
      else if(arr[i]*arr[left]*arr[right] < target){
        left++;
      }
      else
        right--;
    }
    while(i < n-1 && arr[i] == arr[i+1])
      i++;
    i++;
  }
  cout<<count<<endl;
}
