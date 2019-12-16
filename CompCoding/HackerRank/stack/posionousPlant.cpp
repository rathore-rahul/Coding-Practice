#include<iostream>
using namespace std;
typedef long long int lli;
int arr[1000000];
int ans=0;
#include<stack>
int main()
{
  int n;
  cin>>n;
  for(int  i=0;i<n;i++){
    cin>>arr[i];
  }
  stack<pair<int,int>  >  s;
  s.push(make_pair(arr[n-1],0));
  for(int i=n-2;i>=0;i--)
  {
    int count=0;
    while((!s.empty()) && s.top().first>arr[i])
    {
      count=max(count+1,s.top().second);
      s.pop();
    }
    ans=max(ans,count);
    s.push(make_pair(arr[i],count));
  }
  cout<<ans<<endl;
}
