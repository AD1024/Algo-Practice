#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int MAXN = 10001;
int VID = 2;
bool vis[MAXN];
vector<int> v;

int main(){
  int n;
  cin>>n;
  v.push_back(1);
  vis[1]=true;
  for(int i=1;i<n;i++){
    int u,id;
    int pos=0;;
    cin>>u>>id;
    for(int j=0;j<v.size();j++){
      if(u==v[j]){
        pos=j;
        break;
      }
    }
    if(id){
      vis[VID]=true;
      v.insert(v.begin()+pos+1,VID++);
    }else{
      vis[VID]=true;
      if(u==v[0]){
        v.insert(v.begin(),VID++);
        continue;
      }
      v.insert(v.begin()+pos-1, VID++);
    }
  }
  int delNum;
  cin>>delNum;
  for(int i=0;i<delNum;i++){
    int id;cin>>id;
    vis[id]=false;
  }
  for(int i=0;i<v.size();i++){
    if(vis[v[i]]){
      cout<<v[i]<<" ";
    }
  }
  return 0;
}
