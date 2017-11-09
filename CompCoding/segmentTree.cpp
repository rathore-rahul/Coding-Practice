#include <bits/stdc++.h>
using namespace std;
#define INF 1E9

int queryUtil(int st[], int si, int ss, int se, int qs, int qe){
  if(qs <= ss && se <= qe){
    return st[si];
  }
  if(se < qs || qe < ss){
    return INF;
  }
  else{
    int mid = (ss+se)/2;
    int left = queryUtil(st, 2*si+1, ss, mid, qs, qe);
    int right = queryUtil(st, 2*si+2, mid+1, se, qs, qe);
    return min(left, right);
  }
}

int query(int st[], int n, int qs, int qe){
  return queryUtil(st, 0, 0, n-1, qs, qe);
}

void updateSTUtil(int st[], int si, int ss, int se, int index, int newVal){
  if(ss == se && se == index){
    st[si] = newVal;
    return;
  }
  if(index < ss || index > se){
    return;
  }
  else{
    int mid = (ss+se)/2;
    updateSTUtil(st, 2*si+1, ss, mid, index, newVal);
    updateSTUtil(st, 2*si+2, mid+1, se, index, newVal);
    st[si] = min(st[2*si+1],st[2*si+2]);
  }
}

void updateST(int st[], int n, int index, int newVal){
  updateSTUtil(st, 0, 0, n-1, index , newVal);
}

void constructSTUtil(int arr[], int as, int ae, int st[], int si){
  if(as == ae){
    st[si] = arr[ae];
    return;
  }
  int mid = (as+ae)/2;
  constructSTUtil(arr, as, mid, st, 2*si+1);
  constructSTUtil(arr, mid+1, ae, st, 2*si+2);
  st[si] = min(st[2*si+1], st[2*si+2]);
}

int * constructST(int arr[], int n){
  int x = ceil(log2(n));
  int max_size = 2*(1<<x) - 1;
  int *st = new int[max_size];
  constructSTUtil(arr, 0, n-1, st, 0);
  return st;
}

int main(){
  int arr[] = {1, 3, 5, 7, 9, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
  int *st = constructST(arr, n);
  cout<<query(st,n,0,3)<<endl;
  cout<<query(st,n,1,4)<<endl;
  cout<<query(st,n,1,3)<<endl;
  cout<<query(st,n,2,5)<<endl;
  cout<<"updating\n";
  arr[1] = 0;
  updateST(st,n,1,0);
  cout<<query(st,n,0,3)<<endl;
  cout<<query(st,n,1,4)<<endl;
  cout<<query(st,n,1,3)<<endl;
  cout<<query(st,n,2,5)<<endl;
  cout<<"updating\n";
  arr[1] = 3;
  updateST(st,n,1,3);
  cout<<query(st,n,0,3)<<endl;
  cout<<query(st,n,1,4)<<endl;
  cout<<query(st,n,1,3)<<endl;
  cout<<query(st,n,2,5)<<endl;
}
