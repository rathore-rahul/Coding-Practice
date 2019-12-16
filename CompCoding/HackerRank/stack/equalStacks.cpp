#include<bits/stdc++.h>
using namespace std;

#define si(N) scanf("%d", &N)
#define sii(N,L) scanf("%d %d",&N,&L)
#define sl(N) scanf("%lld", &N)
#define pb push_back
#define pi(L) printf("%d\n", L)
#define pl(L) printf("%lld\n", L)
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

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

const int MOD = 1E9 + 7;

lli pow(lli base,lli exponent,lli modulo){
	lli result = 1;
	while(exponent > 0){
		if(exponent%2 == 1)
			result = (result*base)%modulo;
		exponent = exponent>>1;
		base = (base * base)%modulo;
	}
	return result;
}

struct UnionFind {
	vector<int> data;
	set<pii> gsize;
  UnionFind(int n){ init(n); }
	void init(int n) {
		data.assign(n, -1);
		rep(i,n){
			gsize.insert(mp(1,i));
		}
	}
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			gsize.erase(mp(size(y),y));
			gsize.erase(mp(size(x),x));
			data[x] += data[y]; data[y] = x;
			gsize.insert(mp(size(x),x));
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
int main(){
    int n[3];
    int w[3];
    mset(w,0);
    int temp;
    mset(n,0);
    rep(i,3){
        si(n[i]);
    }
    queue<int> st[3];
    rep(i,3){
        rep(j,n[i]){
            si(temp);
            st[i].push(temp);
            w[i] += temp;
        }
    }
    bool flag = false;
    while(!flag){
        if(w[0] == w[1] && w[1] == w[2])
            break;
        int pos = max_element(w,w+3) - w;
        cerr<<pos<<" ";
        temp = st[pos].front();
        st[pos].pop();
        w[pos] -= temp;

    }
    cout<<w[0]<<endl;
}
