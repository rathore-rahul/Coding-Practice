#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define maxsize 100001

long long int cont(long long int a[],int n)
    {
    long long int sum =LLONG_MIN;
    for(int i =1;i<=n;i++)
        {
        if(a[i]+a[i-1] > a[i])
            a[i] += a[i-1];
    }
    for(int i =1;i<=n;i++)
        {
        if(a[i] > sum)
            sum = a[i];
}
    return sum;
}

long long int noncont(long long int a[],int n)
    {
    long long sum =0;
    bool flag = false;int index;
    long long int max = a[1];
    for(int i =1;i<=n;i++)
        {
        if(a[i] >=0)
            {flag = true;index = i;break;}
        if(a[i] > max)
            max = a[i];
    }
    if(!flag)
        return max;
    sum = a[index];
    for(int i= 1;i<=n;i++)
        {
        if(i != index)
            {
            if(sum + a[i] > sum)
                sum += a[i];
    }
    }
    return sum;
}

int main() {
    long long int arr[maxsize] = {0LL};
    int t,n;
    cin>>t;
    arr[0] =0LL;
    while(t--)
    {
        cin>>n;
        if(n==0)
        {cout<<'0'<<endl;
         break;}
        for(int i =1;i<=n;i++)
        {
            cin>>arr[i];
        }
        long long int sum1  = noncont(arr,n);
        long long int sum2 = cont(arr,n);
        printf("%lld %lld\n",sum2,sum1);
    }
    return 0;

}
