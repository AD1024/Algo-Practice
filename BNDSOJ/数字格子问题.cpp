#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <map>
using namespace std;

struct Pos{
    int a[9];
    int step;
    int& operator[](int x) {
        return a[x];
    }
};

queue<Pos> q;
map<string, bool> vis;
Pos End;
inline string Hash(Pos p) {
    string x = "";
    for(int i=1;i<=8;++i) {
        x += p[i] + '0';
    }
    return x;
}

inline void enqueue(Pos p) {
    if(!vis[Hash(p)]) {
        // for(int i=1;i<=8;++i) cout<<p[i]<<" ";
        // puts("");
        q.push(p);
    }
}

inline void bfs() {
    Pos k, start, nxt;
    start.step = 0;
    for(int i=1;i<=4;++i) start.a[i] = i;
    for(int i=5;i<=8;++i) start.a[i] = 8-i+5;
    swap(start, End);
    string end_cond = Hash(End);
    q.push(start);
    while(!q.empty()) {
        k = q.front();
        q.pop();
        if(Hash(k) == end_cond) {
            printf("%d\n", k.step);
            return;
        }
        nxt.step = k.step + 1;
        // 1
        for(int i=1;i<=4;++i) {
            nxt.a[i] = k[i+4];
        }
        for(int i=5;i<=8;++i) {
            nxt.a[i] = k[i-4];
        }
        enqueue(nxt);
        // 2
        for(int i=2;i<=4;++i) {
            nxt.a[i] = k[i-1];
        }
        nxt.a[1] = k[4];
        for(int i=6;i<=8;++i) {
            nxt[i] = k[i-1];
        }
        nxt.a[5] = k[8];
        enqueue(nxt);
        // 3
        memcpy(nxt.a, k.a, sizeof(k.a));
        swap(nxt.a[3], nxt.a[6]);
        swap(nxt.a[2], nxt.a[3]);
        swap(nxt.a[6], nxt.a[7]);
        enqueue(nxt);
    }
}

int main() {
    End.step = 0;
    for(int i=1;i<=8;++i) {
        scanf("%d", &End.a[i]);
    }
    bfs();
    return 0;
}