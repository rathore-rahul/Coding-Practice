#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(int i =0; i < n ;i++){
            cin>>A[i];
        }
        if(n < 2) {cout<<"0\n";continue;}
        int max0 = max(abs(1-A[0]),0) , max1 = max(abs(A[1]-A[0]),abs(A[1]-1));
        for(int i = 2; i < n ;i++){
            int temp0 = max(max0 + abs(1-1),max1 + abs(1-A[i-1]));
            int temp1 = max(max0 + abs(A[i]-1), max1 + abs(A[i]-A[i-1]));
            max0 = temp0;
            max1 = temp1;
        }
        cout<<max(max0,max1)<<endl;
    }
}
