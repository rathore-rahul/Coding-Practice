#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int vals[51];
long long int dp[51][251] = {{0LL}};

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int amount;
    int n;
    cin>>amount>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&vals[i]);    
    }

    sort(vals+1,vals+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j =1;j<=amount;j++)
        {   
            dp[i][j] = dp[i-1][j];
            int temp = j - vals[i];
            while(temp > 0)
                {
                dp[i][j] += dp[i-1][temp];
                temp = temp - vals[i];
            }
            if(temp == 0)
                dp[i][j]++;
        }
    }
    cout<<dp[n][amount]<<endl;
    
    return 0;
}
