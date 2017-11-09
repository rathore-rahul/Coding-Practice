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
        cin>>s;
        s = s+'0';
        int counter = 0;
        for(int i = 0; i < s.length()-1 ;i++){
            if(s[i] == s[i+1])
                counter++;
        }
        cout<<counter<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
