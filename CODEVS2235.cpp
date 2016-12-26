#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  unsigned int price;
  float cut;
  cin>>price;
  cin>>cut;
  int cmp=(int)price*cut/10;
  if(cmp%10>=5){
    while(cmp%10!=0){
      cmp+=1;
    }
    cout<<cmp;
  }else{
    while(cmp%10!=0){
      cmp-=1;
    }
    cout<<cmp;
  }
  return 0;
}
