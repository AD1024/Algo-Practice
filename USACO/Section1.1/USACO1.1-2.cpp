/*
ID: ccodera1
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
inline void filein(){
  freopen("gift1.in","r",stdin);
  freopen("gift1.out","w",stdout);
}

inline void closefile(){
  fclose(stdin);
  fclose(stdout);
}
const int MAXN = 40;
map<string, pair<int,int> > m;
string names[MAXN];
int main(){
    filein();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        m.insert(pair<string,pair<int,int> >(name, pair<int,int>(0,0)));
        names[i]=name;
    }
    int mon,pop;
    string g;
    for(int k=0;k<n;k++){
        cin>>g;
        cin>>mon>>pop;
//        if(pop==0) break;
        m.find(g)->second.first=mon;
        int every;
        if(pop!=0){
            m.find(g)->second.second+=mon%pop;
            every = mon/pop;
        }else{
            every=0;
        }
        for(int i=0;i<pop;i++){
            string rec;cin>>rec;
            m.find(rec)->second.second+=every;
        }
    }
    for(int i=0;i<n;i++){
        cout<<names[i]<<" "<<m.find(names[i])->second.second-m.find(names[i])->second.first<<endl;
    }
    closefile();
    return 0;
}
