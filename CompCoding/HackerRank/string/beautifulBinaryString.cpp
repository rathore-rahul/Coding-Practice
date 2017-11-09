#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    string s;
    cin>>n>>s;
    int state = 0;
    int counter = 0;
    for(int i = 0; i < n ; i++){
        if(s[i] == '0'){
            if(state == 2){
                state = 0;
                counter++;
            }
            else if(state == 0){
                state = 1;
            }
        }
        else{
            if(state == 1){
                state = 2;
            }
            else
                state = 0;
        }
    }
    cout<<counter<<endl;
}
