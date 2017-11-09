#include <iostream>
using namespace std;

int **graph;
int *visited;
int *stack;
int *orderedstack; 
int index, cyclestartNode;

bool isCyclic(int node,int n){
	visited[node] = true;
	stack[node] = 1;
	orderedstack[index++] = node;
	for(int i =0; i < n ;i++){
		if(graph[node][i] == 0)	continue; // no edge present
		else if(stack[i] == 1){  // back edge
			cyclestartNode = i;
			return true;
		}
		else if(visited[i] == 0){  // not visited yet  case of visited and not in stack will not create cycle
			bool flag = isCyclic(i,n);
			if(flag)
				return true;
		}
	}
	stack[node] = 0;
	index--;
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
		for(int j =0; j < n ; j++){
			cin>>graph[i][j];
		}
	}
	visited = new int[n];
	stack = new int[n];
	orderedstack = new int[n];
	bool flag = false;
	for(int i =0; i < n ; i++){
		if(!visited[i]){
			flag =  isCyclic(i,n);
			if(flag)
				break;
		}
	}
	if(flag){
		for(int i =cyclestartNode; i < index; i++){
			cout<<orderedstack[i]<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<-1<<endl;
	}
}