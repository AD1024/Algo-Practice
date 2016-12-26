#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

vector<char> topo;
queue<char> q;
vector<char> g[100];
int in[100];
bool idx[100];
int tot=0;
int N,M;
int T=0,type=-1;
int errorNum,corrNum;
int stubin[100];

inline void Topo(){
    for(int i='A';i<='Z';++i){
        if(idx[i] && in[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    char k;
    topo.clear();
    while(q.size()){
        k=q.front();
        q.pop();
        topo.push_back(k);
        cnt++;
        for(int i=0;i<g[k].size();++i){
            in[g[k][i]]--;
            if(in[g[k][i]]==0){
                q.push(g[k][i]);
            }
        }
    }
    if(cnt<tot && type!=1){
        type=1;
        errorNum=T;
    }else if(tot==N && cnt==tot && type!=0){
        type=0;
        corrNum=T;
    }
}

inline void add(char u,char v){
    g[u].push_back(v);
    if(!idx[u]) ++tot;
    if(!idx[v]) ++tot;
    idx[u]=idx[v]=true;
    in[v]++;
}

inline void copy(){
    for(int i='A';i<='Z';++i){
        stubin[i]=in[i];
    }
}

inline void paste(){
    for(int i='A';i<='Z';++i){
        in[i]=stubin[i];
    }
}

inline void out(){
    printf("Sorted sequence determined after %d relations: ",corrNum);
    for(int i=0;i<topo.size();++i){
        cout<<topo[i];
    }
    cout<<".";
}

int main(){
    cin>>N>>M;
    char str[4];
    while(M--){
        ++T;
        cin>>str;
        add(str[0],str[2]);
        copy();
        if(type!=1)
            Topo();
        paste();
    }
    if(tot<N){
        puts("Sorted sequence cannot be determined.");
        return 0;
    }
    switch(type){
        case 0:out();break;
        case 1:printf("Inconsistency found after %d relations.",errorNum);break;
        default:break;
    }
    return 0;
}