#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TrieNode{
    int count = 0;
    TrieNode* children[26];
};

int main() {
    int n;
    cin>>n;
    TrieNode* root = new TrieNode();
    while(n--){
        string s,t;
        cin>>s>>t;
        if(s == "add"){
            TrieNode * temp = root;
           for(int i =0; i < t.length(); i++){
              int pos = t[i] - 'a';
               if(temp->children[pos] == NULL){
                   temp->children[pos] = new TrieNode();
               }
               (temp->children[pos])->count += 1;
               temp = temp->children[pos];
           }
        }
        else{
            TrieNode * temp = root;
            bool flag = true;
            for(int i =0; i < t.length() ;i++){
                int pos = t[i] - 'a';
                if(temp->children[pos] == NULL)
                {
                    flag = false;
                    break;
                }
                temp = temp->children[pos];
            }
            if(flag)
                cout<<temp->count<<"\n";
            else
                cout<<"0\n";
        }
    }
}
