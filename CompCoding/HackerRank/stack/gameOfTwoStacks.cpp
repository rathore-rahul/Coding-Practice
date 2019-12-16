#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    lli g,n,m,temp,k;
    cin>>g;
    while(g--){
        cin>>n>>m>>k;
        vector<lli> s1(n),s2(m);
        for(int i = 0; i < n ;i++){
            cin>>s1[i];
            if(i != 0)
                s1[i] += s1[i-1];
        }
        for(int i = 0; i < m ;i++){
            cin>>s2[i];
            if( i != 0)
                s2[i] += s2[i-1];
        }
        lli counter = upper_bound(s2.begin(),s2.end(),k) -s2.begin();
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] > k)
                break;
            lli temp_counter=  0LL;
            temp_counter = upper_bound(s2.begin(),s2.end(),k-s1[i]) - s2.begin();
            temp_counter += (i+1);
            counter = max(temp_counter,counter);
        }
        cout<< counter << endl;
    }
}
