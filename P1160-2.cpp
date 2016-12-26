#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;
const int MAXN = 100001;
bool vis[MAXN];
list<int> l;
int VID=2;
int main(){
  memset(vis,false,sizeof(vis));
  int n;
  cin>>n;
  l.push_back(1);
  vis[1]=true;
  for(int i=1;i<n;i++){
    int id,par;
    list<int>::iterator it;
    it = l.begin();
    cin>>id>>par;
    while(1){
      if(*it==id) break;
      it++;
    }
    if(par){
      l.insert(++it,VID);
      vis[VID++]=true;
    }else{
      if(l.front()==id){
        l.push_front(VID);
        vis[VID++]=true;
      }else{
        l.insert(--it,VID);
        vis[VID++]=true;
      }
    }
  }
  int dnum;
  cin>>dnum;
  for(int i=0;i<dnum;i++){
    int id;cin>>id;
    vis[id]=false;
  }
  list<int>::iterator it;
  it=l.begin();
  while(it!=l.end()){
    if(vis[*it]){
      cout<<*it<<" ";
    }
    it++;
  }
  return 0;
}
