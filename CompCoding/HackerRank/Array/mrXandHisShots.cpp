#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,left,right;
	cin>>n>>m;
    vector<int> v1,v2;
	for(int i = 0; i<n;i++){
		cin>>left>>right;
		v1.push_back(left), v2.push_back(right);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	long long int ans = n*1LL*m;
	for(int i = 1;i<=m;i++){
		cin>>left>>right;
		ans -= (v1.end() - upper_bound(v1.begin(),v1.end(),right)) ;
		ans -= (upper_bound(v2.begin(),v2.end(),left-1) - v2.begin());
	}
	cout<<ans;
}
