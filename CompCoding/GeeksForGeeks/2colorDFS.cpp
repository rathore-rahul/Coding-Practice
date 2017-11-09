#include <iostream>
using namespace std;

bool isPossible(int root, int visited[], int color[],int n, int **arr){
	visited[root] = true;
	bool flag = true;
	for(int i =0; i < n; i++){
		if(i == root || arr[root][i] == 0) continue;
		else if(visited[i] == 0){
			color[i] = 1-color[root];
			flag = isPossible(i,visited,color,n,arr);
		}
		else{
			if(color[root] == color[i]) flag = false;
		}
		if(flag == false)
			return false;
	}
	return flag;
}

int main(){
	int n,m;
	cin>>n>>m;
	int **arr = new int*[n];
	for(int i =0; i < n ; i++){
		arr[i] = new int[n];
	}
	for(int i =0;  i < m ; i++){
		int u,v;
		cin>>u>>v; u--;v--;
		arr[u][v] = arr[v][u] = 1;
	}
	int visited[n] = {0};
	int color[n] = {0};
	bool flag = true;
	for(int i =0; i <n; i++){
		if(visited[i] == 0){
			color[i] = 0;
			flag = isPossible(i,visited,color,n,arr);
		}
		if(!flag)
			break;
	}
	cout<<flag<<endl;
}
