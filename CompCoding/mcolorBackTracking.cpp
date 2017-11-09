#include <iostream>
#include <string.h>
using namespace std;

int **graph;

bool isColorable(int **graph, int color[], int v, int n, int m){
	if(v == n) return true;
	for(int i = 0; i < m ; i++){
		bool taken = false;
		for(int j =0; j < n; j++){
			if(graph[v][j] && color[j] == i)
				taken = true;
		}
		if(!taken){
			color[v] = i;
			bool flag = isColorable(graph,color,v+1,n,m);
			if(flag) return true;
			color[v] = -1;
		}
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	graph = new int* [n];
	for(int i =0; i < n ; i++){
		graph[i] = new int[n];
	}
	for(int i =0; i < n ; i++){
		for(int j =0; j < n; j++){
			cin>>graph[i][j];
		}
	}
	int m;
	cin>>m;

	int color[n];
	memset(color,-1,sizeof(color));
	bool flag = isColorable(graph,color,0,n,m);
	cout<<flag<<endl;
}