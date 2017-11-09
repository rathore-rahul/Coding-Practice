#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    string s;
    cin>>n;
    while(n--){
        string ans = "no answer";
        cin>>s;
        int i = s.length()-1;
        for(i ; i > 0 ; i--){
            if(s[i-1] < s[i]){
                for(int j = s.length()-1; j >= i ; j--){
                    if(s[j] > s[i-1]){
                        swap(s[i-1],s[j]);
                        break;
                    }
                }
                sort(s.begin()+i,s.end());
                ans = s;
                break;
            }
        }
        cout<<ans<<endl;
    }
}
