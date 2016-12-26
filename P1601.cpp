#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
stack<int> ans;
int main(){
  char a[100001];
  char b[100001];
  scanf("%s %s",a,b);
  int lena = strlen(a)-1;
  int lenb = strlen(b)-1;
  int pa,pb;
  bool flag=false;
  int pt;
  while(lena>=0 || lenb>=0){
    if(lena<0) pa=0;
    else pa = a[lena]-'0';
    if(lenb<0) pb=0;
    else pb = b[lenb]-'0';
    pt = pa+pb;
    if(flag){
      pt+=1;
    }
    if(pt>=10){
      flag=true;
      pt%=10;
    }else{
      flag=false;
    }
    ans.push(pt);
    lena--;
    lenb--;
  }
  if(flag){
    ans.push(1);
  }
  while(!ans.empty()){
    cout<<ans.top();
    ans.pop();
  }
  return 0;
}
