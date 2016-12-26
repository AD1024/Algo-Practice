#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
// void cnt(int n){
//   if(n/2<0) return;
//   cc++;
//   for(int i=1;i<=n/2;i++){
//     cnt(i);
//   }
// }
/*
这题数据比较弱..用递归确实可以过。动规也是可以的
F[i]:以i开始可以组成的个数
F[i]=F[i]+F[j] (1<=i<=N && 0<=j<=i/2)
F[0]=1 (0的话只有一个.)
数据比较弱，数组不开long long也可以过...亲测1000 int是会炸的。
*/
int main(){
  int n;
  cin>>n;
  int d[1002];
  d[0]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=i/2;j++){
      d[i]+=d[j];
    }
  }
  cout<<d[n];
  return 0;
}
