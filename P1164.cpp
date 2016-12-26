#include <iostream>
using namespace std;
const int MAXN = 1010;
int main(){
  int N,M;
  cin>>N>>M;
  int V[MAXN];
  memset(V,0,sizeof(V));
  for(int i=1;i<=N;i++){
    cin>>V[i];
  }
  int F[MAXN];
  memset(F,0,sizeof(F));
  F[0]=1;
  for(int i=1;i<=N;i++){
    for(int j=M;j>=V[i];j--){
      F[j]+=F[j-V[i]];
    }
  }
  cout<<F[M];
  return 0;
}
