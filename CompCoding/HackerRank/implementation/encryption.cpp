#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin>>s;
    int l = floor(sqrt(s.length()));
    int h = ceil(sqrt(s.length()));
    int row = l,col=l;
    for(int i =l; i <=h ;i++){
        for(int j =l; j <=h ;j++){
            if(i*j >= s.length()){
                row = i;
                col = j;
                goto SOS;
            }
        }
    }
    SOS:
    for(int j =0; j < col ;j++){
        for(int i =0; i < row ;i++){
            if(i*col + j >= s.length())
                continue;
            cout<<s[i*col+j];
        }
        cout<<" ";
    }
}
