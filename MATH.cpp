#include <iostream>
using namespace std;

int main(){
  int cnt;
  int sum=0;
  for(int i=100;i<=1000;i++){
    if(i%3==0 || i%5==0){
      cnt+=1;
      sum+=i;
    }
  }
  cout<<"Count:"<<cnt<<endl<<"Sum:"<<sum<<endl;
  return 0;
}
