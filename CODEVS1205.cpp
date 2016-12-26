#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
int main(){
  char str[100][100];
  int cnt=0;
  while(scanf("%s",str[cnt++])!=EOF);
  while(cnt){
    printf("%s",str[--cnt]);
  }
  return 0;
}
