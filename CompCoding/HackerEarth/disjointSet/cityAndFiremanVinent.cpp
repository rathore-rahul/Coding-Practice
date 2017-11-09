#include<bits/stdc++.h>
using namespace std;

#define S(N) scanf("%d", &N)
#define SL(N) scanf("%lld", &N)
#define pb push_back
#define P(L) printf("%d\n", L)
#define PL(L) printf("%lld\n", L)
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define xx first
#define yy second
#define mod (int)(1e9+7)
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;


struct UnionFind {
	vector<int> data;
	int distinct_set;
	vector<int> risk;
	vector<int> num_min_risk;
  UnionFind(int n){ init(n); }
	void init(int n) { data.assign(n, -1); distinct_set = n;
	risk.assign(n,-1); num_min_risk.assign(n,1);}
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
			if(risk[x] < risk[y]);
			else if(risk[y] < risk[x]){
				num_min_risk[x] = num_min_risk[y];
				risk[x] = risk[y];
			}
			else{
				num_min_risk[x] += num_min_risk[y];
			}
			distinct_set--;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

int main(){
	int n;
	S(n);
	UnionFind uf(n);
	rep(i,n){
		S(uf.risk[i]);
	}
	int k;
	S(k);
	rep(i,k){
		int u,v;
		S(u);S(v);
		uf.unionSet(u-1,v-1);
	}
	lli ans = 1LL;
	rep(i,n){
		if(uf.data[i] < 0){
			ans = (ans * uf.num_min_risk[i])%mod;
		}
	}
	PL(ans);
}
