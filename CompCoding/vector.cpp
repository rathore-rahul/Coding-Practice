#include <bits/stdc++.h>
using namespace std;

// declaring vector
vector<int> vec(n);

// declaring vector from other containers
vector<int> vec(vec2.begin(),vec2.end());

//declaring matrix
vector<vector<int> > mat(N,vector<int> (M));

// resize(doesn't clear) and clear
vec.resize(10);  vec.clear();

//reverse vector
reverse(vec.begin(),vec.end());

//find element
find(vec.begin(),vec.end(),value);

// max min element
auto it = max_element(vec.begin(),vec.end());
auto it = min_element(vec.begin(),vec.end());

//another way for auto
typeof(a+b) x = (a+b);

// inserting value at index i all values will be shifted to right
vec.insert(index,value);
vec.insert(index,vec2.begin(),vec2.begin());

//erase
vec.erase(iterator it);
vec.erase(iterator start, iterator end);


// next permutation
next_permutation(all(vec));
prev_permutation(all(vec));

//sum of all elements
int sum = accumulate(all(v), 0);
int product = accumulate(all(v), 1, multiplies<int>());

// inner product
int r = inner_product(all(v1), v2.begin(), 0);
