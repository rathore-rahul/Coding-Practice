#include <bits/stdc++.h>
using namespace std;



int main() {
    std::ios::sync_with_stdio(false);
    int n,q,t;
    cin>>n>>q;
    stack<int> s1,s2,s3;
    for(int i =0; i < n ; i++){
        cin>>t;
        s1.push(t);
    }
    vector<int> primes;
    int count = 0;
    int i = 1;
    while(count < q){
        i++;
        bool flag = true;
        for(int j = 2; j*j <= i ;j++){
            if(i%j == 0)
            {
                flag =false;
                break;
            }
        }
        if(flag)
        {
            primes.push_back(i);
            count++;
        }
    }
    i = 0;
    while(i < q && !s1.empty()){
        int prime = primes[i];
        while(!s1.empty()){
            t = s1.top();
            s1.pop();
            if(t%prime == 0)
               s2.push(t);
            else
                s3.push(t);
        }
        while(!s2.empty()){
            cout<<s2.top()<<"\n";
            s2.pop();
        }
        s1.swap(s3);
        i++;
    }
    while(!s1.empty())
    {
        cout<<s1.top()<<"\n";
        s1.pop();
    }
}
