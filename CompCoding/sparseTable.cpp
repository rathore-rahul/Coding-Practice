#include <bits/stdc++.h>
using namespace std;

int table[100][10];

int *arr;
int n;

void buildTable(){
  for(int i =0; i < n ;i++){
    table[i][0] = arr[i];
  }
  for(int j = 1; j < 10 ;j++){
    if((1<<j) > n)
      break;
    for(int i =0; i <= (n- (1<<j));i++){
      table[i][j] = min(table[i][j-1],table[i+(1<<j-1)][j-1]);
    }
  }
}

int query1(int l,int r){
  int len = r-l+1;
  int idx = floor(log2(len));
  int rem_len = len - (1 <<idx);
  int z = min(table[l][idx],table[l+rem_len][idx]);
  return z;
}

int query(int l,int r){
  int answer = 1E9;
  for(int k = 9; k >= 0;k--){
    if(l+(1<<k) > r)
      continue;
    answer = min(answer,table[l][k]);
    l += (1<<k);
  }
  return answer;
}

int main(){
  int a[] = {7, 2, 3, 0, 5, 10, 3, 12, 18};
  n = sizeof(a)/sizeof(a[0]);
  arr = a;
  buildTable();
  cout<<query1(0,4)<<endl;
  cout<<query(0,4)<<endl;
  cout<<query1(4,7)<<endl;
  cout<<query(4,7)<<endl;
  cout<<query1(7,8)<<endl;
  cout<<query(7,8)<<endl;
}
