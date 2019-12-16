#include <bits/stdc++.h>
using namespace std;

#define s(n) scanf("%lld",&n)
typedef vector<int> vi;
typedef long long int lli;
#define mod 1000000007

int main(){
    long long int n;
    s(n);
    vi cluster(n+1);
    vi cluster_size(n+1);
    for(int i = 1; i < n+1; i++){
        cluster[i] = i;
        cluster_size[i] = 1;
    }
    for(int i= 1; i < n+1; i++){
        int j,k;
        char c;
        cin>>j>>k>>c;
        if(c == 'b'){
            while(cluster[j] != j)
                j = cluster[j];
            while(cluster[k] != k)
                k = cluster[k];
            if(j == k);
            else if(cluster_size[j] >= cluster_size[k]){
                cluster[k] = j;
                cluster_size[j] += cluster_size[k];
            }
            else{
                cluster[j] = k;
                cluster_size[k] += cluster_size[j];
            }
        }
    }
    long long int total_triplets = n*(n-1)*(n-2)/6;
    long long int all_black = 0LL;
    vector<bool> done(n+1,false);
    for(int i = 1; i < n+1; i++){
        int k = i;
        while(cluster[k] != k){
            k = cluster[k];
        }
        if(done[k])
        	continue;
        done[k] = true;
        if(cluster_size[k] > 2 ){
            long long int l = (long long int)cluster_size[k];
            all_black += l*(l-1)*(l-2)/6;
        }
        if(cluster_size[k] > 1){
            long long int l = (long long int)cluster_size[k];
            all_black += (n-l)*l*(l-1)/2;
        }
    }
   long long int ans = ((total_triplets%mod - all_black%mod) + mod)%mod;
   cout<<ans<<endl;
}
