#include <bits/stdc++.h>
using namespace std;
#define s(n)  scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define forall(i,a,b) for(int i=a;i<b;i++)
typedef vector<int> vi;

int main() {
  int n,q;
  scanf("%d %d\n",&n,&q);
  vi community(n+1);
  vi num_people(n+1);
  forall(i,1,n+1){
    community[i] = i;
    num_people[i] = 1;
  }
  forall(k,0,q){
    char type;
    std::cin >> type;
    if(type == 'M'){
      int i,j;
      std::cin >> i >>  j;
      while(community[i] != i)
        i = community[i];
      while(community[j] != j)
        j = community[j];
        if(i != j){
          if(num_people[i] > num_people[j]){
            community[j] = i;
            num_people[i] += num_people[j];
          }
          else{
            community[i] = j;
            num_people[j] += num_people[i];
          }
        }
    }
    else{
      int i;
      std::cin >> i;
      while(community[i] != i)
        i = community[i];
      printf("%d\n",num_people[i]);
    }
  }
}
