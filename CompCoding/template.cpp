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

/** Declaring containers      * Declaring containers required class or struct to overload operator()
																while using a algorithm or function like sort require a function*.
*/
/**Chill Type containers
	*/
	stack<int> mystack;
	queue<int> myqueue;
	vector<int> vec;

/**priority_queue
	*/
	class Compare
	{
	public:
	    bool operator() (Foo left, Foo right)
	    {
	        return true;    // remember the root node is the max_element according to this Comparator
													// if true right will be on front of the heap else left will be on the front;
	    }
	};
	priority_queue<int> max_heap;
	priority_queue<int, std::vector<int>, std::greater<int> > min_heap; // T,Vector<T> Comparator
	priority_queue<Foo, std::vector<Foo>, Compare> custom_heap;

/**set
	*/
	set<int> st;          /* standard stl min Comparator */
	set<Foo,Compare> st;  /* custom Comparator */


/** Comparator for vector sort
	*/
bool compare(const <T> &left, const <T> &right){
	/* return true if left is small. and use like this sort(vec.begin(),vec.end(),compare); */
}


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

/** Hashing frequency vector of char of a string to unsigned long long
*/
unsigned long long myHash(vi freq)
{
    unsigned long long t=1,ret=0;
    for(int i=0; i<26; i++)
    {
        ret += t*freq[i];
        t=t*(unsigned long long)1000003;
    }
    return ret;
}

struct UnionFind {
	vector<int> data;
  UnionFind(int n){ data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

struct trie_node{
	int value;
	trie_node *children[ALPHABET_SIZE];

	trie_node(){
		val = 0;
		for(int i = 0; i < ALPHABET_SIZE; i++){
			children[i] = NULL;
		}
	}

	bool isFreeNode(){							// node with no children
		for(int i = 0; i < ALPHABET_SIZE; i++){
			if(children[ALPHABET_SIZE]){
				return 0;
			}
		}
		return 1;
	}
	bool isLeafNode(){
		return value != 0;
	}

};

struct trie{
	int count;
	trie_node *root;

	trie(){
		count  = 0;
		root = new trie_node();
	}

	void insert(string &key){
		count++;
		trie_node *pCrawl = root;
		for(int i = 0; i < key.length(); i++){
			int index = key[i] -'a';
			if(!pCrawl->children[index]){
				pCrawl->children[index] = new trie_node();
			}
			pCrawl = pCrawl->children[index];
		}
		pCrawl->value = count;
	}

	int search(string &key){
		trie_node *pCrawl = root;
		for(int i = 0; i < key.length(); i++){
			int index = key[i] - 'a';
			if(!pCrawl->children[index]){
				return 0;
			}
			pCrawl = pCrawl->children[index];
		}
		return pCrawl->value;
	}

	bool deleteHelper(trie_node *pNode,string &key, int level){
		if(pNode){
			if(string.length() == level){
				if(pNode->value){
					pNode->value = 0;
					if(pNode->isFreeNode()){
						return true;
					}
					return false;
				}
			}
			else{
				int index = key[level];
				if(deleteHelper(pNode->children[index], key, level+1)){
					delete pNode->children[index];
					return(!pNode->isLeafNode() && pNode->isFreeNode());
				}
			}
		}
		return false;
	}

	void deleteKey(string key){
		deleteHelper(root,key,0);
	}

};
