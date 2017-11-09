#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int i = 0, j = n-1;
    int diff = 0;
    while(i < j){
        if(s[i] != s[j]) {diff++;i++;j--;}
        else {i++;j--;}
    }
    if(diff > k)
    {cout<<"-1";return 0;}
    else
    {
        int i =0,j=n-1;
        while(i <= j){
            if(i == j && k > 0){s[i] = '9';}

            else if(s[i] == s[j]){
                if(s[i] != '9' && k-2 >= diff){
                    s[i] = s[j] = '9';
                    k -= 2;
                }
            }
            else{
                int max_pos = s[i] > s[j] ? i:j;
                int min_pos = s[i] > s[j] ? j:i;
                if(s[max_pos] == '9'){diff--;k--;s[min_pos] = '9';}
                else if(k-1 >= diff){
                    k -= 2;
                    diff--;
                    s[max_pos] = s[min_pos] = '9';
                }
                else { s[min_pos] = s[max_pos] ; k--;diff--;}
            }
            i++;j--;
        }

    }
    cout<<s<<endl;
}
