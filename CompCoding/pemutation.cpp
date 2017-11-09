#include <iostream>
using namespace std;

void permute(int arr[],int pos,int n){
	if(pos == n){
		for(int i =0; i < n ;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i = pos ; i <n ; i++){
		swap(arr[i],arr[pos]);
		permute(arr,pos+1,n);
		swap(arr[i],arr[pos]);
	}
}

int main(){
	int arr[] = {1,4,3,2};
	permute(arr,0,4);
}