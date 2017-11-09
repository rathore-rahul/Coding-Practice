#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TrieNode{
    int count = 0;
    TrieNode* child[26];
};

int main() {
    int n;
    cin>>n;
    TrieNode* root = new TrieNode();
    while(n--){
        string s;
        cin>>s;
        TrieNode * temp = root;
        for(int i =0; i < s.length();i++){
            int index = s[i] -'a';
            if(i == s.length()-1 && temp->child[index] != NULL){
                cout<<"BAD SET\n";
                cout<<s<<endl;
                return 0;
            }
            else if(temp->child[index] == NULL){
                temp->child[index] = new TrieNode();
            }
            else if((temp->child[index])->count != 0 ){
                cout<<"BAD SET\n";
                cout<<s<<endl;
                return 0;
            }
            temp = temp->child[index];
        }
        temp->count += 1;
    }
    cout<<"GOOD SET\n";
}
