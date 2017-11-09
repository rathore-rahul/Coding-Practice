#include <bits/stdc++.h>
using namespace std;

#define F second.first
#define S second.second
#define W first
typedef long long int lli;

lli find_count(vector<lli> & weight,vector<lli> & count,lli l,lli r){
    lli lb = lower_bound(weight.begin(),weight.end(),l) - weight.begin();
    lli ub = upper_bound(weight.begin(),weight.end(),r) - weight.begin();
    lli lower_count = 0LL, upper_count = 0LL;
 	if(lb == weight.size())
        return 0LL;
    else if(lb != 0LL)
        lower_count = count[lb-1LL];
    if(ub == 0LL)
        return 0LL;
    else
        upper_count = count[ub-1LL];
    return upper_count - lower_count;

}

int main() {
    lli n, q;
    cin>>n>>q;
    vector<pair<lli,pair<lli,lli> > > edges(n-1);
    for (lli i =0 ; i < n-1; i++){
        scanf("%lld %lld %lld",&edges[i].F,&edges[i].S,&edges[i].W);
    }
    sort(edges.begin(),edges.end());
    vector<lli> weight(n-1);
    vector<lli> count(n-1);
    vector<lli> rep(n+1);
    vector<lli> cize(n+1,1);
    for(lli i = 1LL; i <= n ;i++){
    	rep[i] = i;
    }
    for(lli i = 0LL; i < n-1 ;i++){
        weight[i] = edges[i].W;
        lli u = edges[i].F, v = edges[i].S;
        while(u != rep[u])
        	u = rep[u];
        while(v != rep[v])
        	v = rep[v];
        if( u  != v){
        	if(cize[u] > cize[v]){
                count[i] +=   (i == 0LL ? cize[u]*cize[v] : count[i-1LL] + cize[u]*cize[v]);
        		cize[u] += cize[v];
        		rep[v] = u;
        	}
        	else{
                count[i] +=   (i == 0LL ? cize[u]*cize[v] : count[i-1LL] + cize[u]*cize[v]);
        		cize[v] += cize[u];
        		rep[u] = v;
        	}
        }
    }
    for(lli i =0LL; i < q ; i++){
        lli l,r;
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",find_count(weight,count,l,r));
    }
}
