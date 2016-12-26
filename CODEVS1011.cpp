#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int m_count=0;
 void solve(int n){
   m_count+=1;
   for(int i=1;i<=n/2;i++){
     solve(i);
   }
 }

int main(){
  int n;
  cin>>n;
  solve(n);
  cout<<m_count;
}
