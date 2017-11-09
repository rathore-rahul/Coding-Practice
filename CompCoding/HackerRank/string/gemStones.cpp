#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<vector<int> > mat(26,vector<int>(n));
    string s;
    for(int i =0; i < n; i++){
        cin>>s;
        for(int j = 0; j < s.length(); j++){
            mat[s[j]-'a'][i] = 1;
        }
    }
    int counter = 0 ;
    for(int i =0; i < 26; i++){
        if(accumulate(mat[i].begin(),mat[i].end(),0) == n)
            counter++;
    }
    cout<<counter<<endl;
}
