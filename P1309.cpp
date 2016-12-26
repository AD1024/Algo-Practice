#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <map>
#include <algorithm>
using namespace std;
const int MAXN = 200001;

inline int readInt(){
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n'){
        a *= 10;
        a += ch - '0';
    }
    return a;
}


struct P{
    int id;
    int score;
    int idx;
}m[MAXN];

P win[MAXN];
P fal[MAXN];

bool cmp(P a,P b){
    if(a.score == b.score){
        return a.id<b.id;
    }else{
        return a.score>b.score;
    }
}

int main(){
    int n,r,q;
    n=readInt();
    r=readInt();
    q=readInt();
    int num = n*2;
    for(int i=1;i<=num;i++){
        m[i].id = i;
        m[i].score=readInt();
    }
    for(int i=1;i<=num;i++){
        m[i].idx=readInt();
    }
    sort(m+1,m+1+num,cmp);
    int cur=1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=num;j+=2){
            if(m[j].idx>m[j+1].idx){
                win[cur]=m[j];
                fal[cur]=m[j+1];
                cur++;
            }else{
              win[cur]=m[j+1];
              fal[cur]=m[j];
              cur++;
            }
        }
        merge(win,win+1+num,fal,fal+1+num,m+1,cmp);
    }
    cout<<m[q].id;
    return 0;
}
