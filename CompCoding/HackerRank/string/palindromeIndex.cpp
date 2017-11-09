#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        int index = -1;
        int i = 0,j = s.length()-1;
        while(i < j){
            if(s[i] != s[j])
            {
                int tempi = i,tempj = j;
                bool flag = true;
                i = tempi+1;
                j = tempj;
                while(i < j){
                    if(s[i] != s[j])
                    {
                        flag =false;
                        break;
                    }
                    i++;j--;
                }
                if(flag){
                    index = tempi;
                }
                else
                    index = tempj;

                break;
            }
            i++;
            j--;
        }
        cout<<index<<endl;
    }
}
