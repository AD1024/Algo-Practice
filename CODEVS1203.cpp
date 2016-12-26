#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
  char a[100];
  char b[100];
  scanf("%s",a);
  scanf("%s",b);
  for(int i=0;i<10;i++){
    if(a[i]!=b[i]){
      cout<<"no";
      return 0;
    }
  }
  cout<<"yes";
  return 0;
}
