#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

pair<string, int> list[21];
vector <int> v;
void init(){
  list[1] = make_pair("one", 1);
  list[2] = make_pair("two", 4);
  list[3] = make_pair("three", 9);
  list[4] = make_pair("four", 16);
  list[5] = make_pair("five", 25);
  list[6] = make_pair("six", 36);
  list[7] = make_pair("seven", 49);
  list[8] = make_pair("eight", 64);
  list[9] = make_pair("nine", 81);
  // list[10] = make_pair("ten", 0);
  list[11] = make_pair("eleven", 21);
  list[12] = make_pair("twelve", 44);
  list[13] = make_pair("thirteen", 69);
  list[14] = make_pair("fourteen", 96);
  list[15] = make_pair("fifteen", 25);
  list[16] = make_pair("sixteen", 56);
  list[17] = make_pair("seventeen", 89);
  list[18] = make_pair("eighteen", 24);
  list[19] = make_pair("nineteen", 61);
  // list[20] = make_pair("twenty", 20);
}

int main(){
  init();
  string a;
  int cnt=0;
  while(cin>>a){
    if(a=="ten" || a=="twenty")
      continue;
    if(a=="a" || a=="another" || a=="first"){
      v.push_back(1);
      continue;
    }
    if(a=="both" || a=="second"){
      v.push_back(2);
      continue;
    }
    if(a=="third"){
      v.push_back(3);
    }
    if(a=="."){break;}
    else{
      for(int i=1;i<=20;i++){
        if(a==list[i].first){
          v.push_back(list[i].second);
        }
      }
    }
  }
  long long ans=0;
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
      ans+=v[i];
      ans*=100;
  }
  cout<<ans/100;
  return 0;
}
