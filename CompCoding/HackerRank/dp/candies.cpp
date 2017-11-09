#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> ratings(n);
    for(int i =0; i < n ;i++){
        cin>>ratings[i];
    }
    vector<int> candies(n,1);

    for(int i = 1; i < n; i++){
        if(ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]){
            candies[i] = candies[i-1] + 1;
        }
    }
    for(int i = n-2 ; i >= 0; i--){
        if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]){
            candies[i] = candies[i+1]+1;
        }
    }

    long long counter = 0;
    for(int i =0; i < n ;i++){
        counter += candies[i];
    }
    cout<<counter<<endl;
}
