#include <bits/stdc++.h>
using namespace std;

#define INF 1E9

struct sparseArray{
  vector<vector<int> > data;
  int n,k;
  sparseArray(vector<int> & arr){
    k = log2(arr.size())+1;
    n = arr.size();
    data.assign(n,vector<int>(k,INF));
    for(int i =0; i < n ; i++){
      data[i][0] = arr[i];
    }
    for(int p = 1; p <= k ; p++){
      for(int i = 0; i <= n-(1<<p); i++){
        data[i][p] = max(data[i][p-1], data[i + (1<<p-1)][p-1]);
      }
    }
  }
  int query_1(int l , int r){
    int ans = INT_MIN;
    for(int i = k; i >= 0 ; i--){
      if(l+ (1<<i) - 1 <=r){
        ans = max(ans,data[l][i]);
        l += 1<<i;
      }
    }
    return ans;
  }
  int query_2(int l , int r){
    int ans = INT_MIN;
    int p = log2(r-l+1);
    int shift = r-l+1 - (1<<p);
    return max(data[l][p],data[l+shift][p]);
  }
};

int main(){
  int nums[] = {1,3,4,2,5,3,5,3,7,9,3,6,9};
  vector<int> arr(nums,nums+13);
  sparseArray sparr(arr);
  cout<<sparr.query_1(6,11)<<endl;
  cout<<sparr.query_2(6,11)<<endl;
}
