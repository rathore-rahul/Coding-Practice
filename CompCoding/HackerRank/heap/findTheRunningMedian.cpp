#include <bits/stdc++.h>

using namespace std;
void print(double val){
    printf("%.1f\n",val);
}
int main() {
    int n,temp;
    cin>>n;
    double median;
    priority_queue<int> lheap;
    priority_queue<int,vector<int>,greater<int> > rheap;
    cin>>temp;
    median = temp;
    lheap.push(temp);
    print(median);
    if(n < 2)
        return 0;
    cin>>temp;
    if(temp >= lheap.top())
        rheap.push(temp);
    else{
        rheap.push(lheap.top());
        lheap.pop();
        lheap.push(temp);
    }
    median = (median + temp)/2;
    print(median);
    for(int i = 2 ; i < n ;i++){
        cin>>temp;
        if(lheap.size() == rheap.size()){
            if(temp > rheap.top()){
                lheap.push(rheap.top());
                rheap.pop();
                rheap.push(temp);
            }
            else
                lheap.push(temp);
            median = lheap.top();
            print(median);
        }
        else{
            if(temp >= lheap.top()){
                rheap.push(temp);
            }
            else{
                rheap.push(lheap.top());
                lheap.pop();
                lheap.push(temp);
            }
            median = (lheap.top() + 0.0 + rheap.top())/2;
            print(median);
        }
    }
}
