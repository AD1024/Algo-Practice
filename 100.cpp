#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  for(int i=1;i<=100;i++){
    for(int j=2;j<=100;j+=2){
      if(i+j>=100) continue;
      if((100-i-j)%3!=0) continue;
        if(i*3+j/2*3+(100-i-j)/3==100)
          cout<<i<<" "<<j<<" "<<100-i-j<<endl;
      }
  }
  return 0;
}
