#include <bits/stdc++.h>
using namespace std;
#define s(n)    scanf("%d",&n)
#define forall(i,a,b)   for(int i = a; i < b; i++)

int main() {
    int n;
    s(n);
    vector<int> rep(2*n+1);
    vector<int> g_size(2*n+1);
    
    forall(i,1,2*n+1){
        rep[i] = i;
        g_size[i] = 1;
    }
    forall(i,1,n+1){
        int j,k;
        s(j);s(k);
        while(rep[j] != j)
               j = rep[j];
        while(rep[k] != k)
               k = rep[k];
        if(j == k){
        }
        else if(g_size[j] > g_size[k]){
            rep[k] = j;
            g_size[j] += g_size[k];
        }
        else{
            rep[j] = k;
            g_size[k] += g_size[j];
        }
    }
    int low = INT_MAX,high = INT_MIN;
    forall(i,1,2*n+1){
        int k = i;
        while(rep[k] != k )
            k = rep[k];
        if(g_size[k] > 1){
            low = min(g_size[k],low);
            high = max(g_size[k],high);
        }
    }
    printf("%d %d\n",low,high);
}
