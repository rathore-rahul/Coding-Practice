#include <iostream>
using namespace std;

struct minHeap{
	int *arr;
	int size;
	int capacity;

	minHeap(int n){
		capacity = n;
		size = 0;
		arr = new int[n];
	}
	~minHeap(){
		delete[] arr;
	}
	void push(int x){
		int pos = size;
		arr[size++] = x;
		while(pos != 0 && arr[pos/2] > arr[pos]){
			swap(arr[pos/2],arr[pos]);
			pos = pos/2;
		}
	}
	bool empty(){return size == 0;}
	int top() { return arr[0];}
	void pop(){
		swap(arr[0],arr[--size]);
		percolate(0);
	}
	void percolate(int i){
		int l = 2*i+1;
		int r = 2*i+2;
		int least = i;
		if(l < size && arr[l] < arr[least]){ least = l;}
		if(r < size && arr[r] < arr[least]){ least = r;}
		if(least != i){
			swap(arr[least],arr[i]);
			percolate(least);
		}
	}
};

int main(){
	int n;
	cin>>n;
	minHeap hp(n);
	for(int i =0; i < n ; i++){
		int t;
		cin>>t;
		hp.push(t);
	}
	for(int i =0; i < n ; i++){
		cout<<hp.top()<<" ";
		hp.pop();
	}
	cout<<endl;
}