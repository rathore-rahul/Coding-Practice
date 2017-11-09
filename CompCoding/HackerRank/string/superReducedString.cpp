#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s){
    string out,in = s;
    s = s + '0';
    for(int i =0 ; i < s.length()-1;i++){
        if(s[i] == s[i+1])
            i++;
        else
            out += s[i];
    }
    if(out == in)
        return out;
    else return super_reduced_string(out);
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    if(result.empty())
        cout<<"Empty String"<<endl;
    else
        cout<<result<<endl;
    return 0;
}
