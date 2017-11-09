#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    cin>>s;
    vector<int> a(26);
    int lo;
    if(s.length()%2 == 0)
        lo = 0;
    else
        lo = 1;
    for(int i =0; i < s.length() ;i++){
        a[s[i]-'a']++;
    }
    for(int i =0; i < 26 ;i++){
        if(a[i]%2 !=0 )
            lo--;
    }
    if(lo == 0)
        cout<<"YES";
    else
        cout<<"NO";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
