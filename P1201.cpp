#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int MAXN = 10001;
map<string, pair<int,int> > m;
string names[MAXN];
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string name;
    cin>>name;
    m.insert(pair<string,int>(name, pair<int,int>(0,0)));
    names[i]=name;
  }
  int mon,pop;
  string g;
  while(cin>>g){
    cin>>mon>>pop;
    // if(pop==0) break;
    m.find(g)->second.first=mon;
    m.find(g)->second.second+=mon%pop;
    int every = mon/pop;
    for(int i=0;i<pop;i++){
      string rec;cin>>rec;
      m.find(rec)->second.second+=every;
    }
  }
  for(int i=0;i<n;i++){
    cout<<names[i]<<" "<<m.find(names[i])->second.second-m.find(names[i])->second.first<<endl;
  }
  return 0;
}
