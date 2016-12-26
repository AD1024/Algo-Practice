#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int g,b,c;
  cin>>g>>b>>c;
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  bool flag=false;
  do {
    int p = a[1]*100+a[2]*10+a[3];
    int q = a[4]*100+a[5]*10+a[6];
    int k = a[7]*100+a[8]*10+a[9];
    if(p*c*b==q*g*c && q*g*c==k*b*g && k*g*b == p*c*b){
      flag=true;
      cout<<p<<" "<<q<<" "<<k<<endl;
    }
  } while(next_permutation(a+1,a+10));
  if(!flag){
    cout<<"No!!!";
  }
  return 0;
}
