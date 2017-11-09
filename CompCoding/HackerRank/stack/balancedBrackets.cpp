#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void check_balanced(string s) {
    stack<char> ps;
    for(int i = 0; i < s.length(); i++) {
        switch(s[i]) {
            case ')' :
            if(ps.empty() || ps.top() != '(') {
                printf("NO\n");
                return;
            }
            else
                ps.pop();
            break;

            case '}' :
            if(ps.empty() || ps.top() != '{'){
                printf("NO\n");
                return;
            }
            else
                ps.pop();
            break;

            case ']' :
            if(ps.empty() || ps.top() != '[') {
                printf("NO\n");
                return;
            }
            else
                ps.pop();
            break;

            default :
            ps.push(s[i]);
            break;
        }
    }
    if(!ps.empty())
        printf("NO\n");
    else
        printf("YES\n");
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        check_balanced(s);
    }
}
