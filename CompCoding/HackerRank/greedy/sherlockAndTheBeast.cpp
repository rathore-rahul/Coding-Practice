#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,t;
    cin>>n;
    while(n--){
        cin>>t;
        int x1 = t-(t%3),x2;
        bool flag = false;
        while(x1 >= 0){
            x2 = t-x1;
            if(x2%5 == 0){
                flag = true;
                break;
            }
            else
                x1 = x1-3;
        }
        if(flag){
            for(int i = 0; i < t;i++){
                if(i < x1)
                    cout<<"5";
                else
                    cout<<"3";
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
