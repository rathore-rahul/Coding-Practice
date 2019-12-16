#include <iostream>
using namespace std;

int partition(int *arr, int low, int high){
	int index = low;
	for(int i = low; i <= high ; i++){
		if(arr[i] <= arr[high]){
			swap(arr[i],arr[index]);
			index++;
		}
	}
	return index-1;
}

void qsort(int *arr, int low, int high){
	if(low < high){
		int pivot = partition(arr,low,high);
		qsort(arr,low,pivot-1);
		qsort(arr,pivot+1,high);
	}
}

int main(){
	int arr[] = {5,6,4,3,2,5,6,7,8,9,10,23,12,31};
	int n = sizeof(arr)/sizeof(arr[0]);
	qsort(arr,0,n-1);
	for(int i =0; i < n ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}