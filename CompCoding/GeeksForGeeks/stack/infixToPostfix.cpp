#include <bits/stdc++.h>
using namespace std;

// bahut haga hai mene 
map<char,int> precd;

void infixToPostFix(const string &s){
    stack<char> st;
    int i =0;
    while( i < s.length()){
        if(s[i] >= 'a' && s[i] <= 'z'){
            cout<<s[i];
            i++;
        }  
        else if(s[i] == '('){
            st.push(s[i]);
            i++;
        }
        else if(s[i] == ')'){
            i++;
            while(!st.empty()){
                char c = st.top();
                st.pop();
                if(c == '(') break;                
                cout <<c;
            }
        }
        else{
            while(!st.empty() && precd[s[i]] <= precd[st.top()]){
                cout<<st.top();
                st.pop();
            }
            st.push(s[i]);
            i++;
        }
    }
    if(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}

int main(){
    precd['/'] = 3;
    precd['*'] = 3;
    precd['+'] = 2;
    precd['-'] = 2;
    precd['^'] = 5;
    precd['('] = 0;
    string s;
    cin>>s;
    infixToPostFix(s);
}