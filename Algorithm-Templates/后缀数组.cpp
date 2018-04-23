#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAXN 101000
#define MAXM 128

int buc[MAXM];
int SA[MAXN], Rank[MAXN], y[MAXN], x[MAXN];
string s;

inline void build() {
    int len = s.size();
    int m = MAXM;
    memset(buc, 0, sizeof(buc));
    for(int i=0;i<len;++i) buc[x[i] = s[i]] += 1;
    for(int i=1;i<m;++i) buc[i] += buc[i - 1];
    for(int i=len-1;i >= 0;--i) SA[--buc[x[i]]] = i;
    for(int k=1;i<=len;k <<= 1) {
        int p = 0;
        for(int i=len-1;i >= len - k;--i) y[p++] = i;
        for(int i=0;i<len;++i) if(SA[i] >= k) y[p++] = SA[i] - k;
        memset(buc, 0, sizeof(buc));
        for(int i=0;i<len;++i) buc[x[y[i]]] += 1;
        for(int i=1;i<m;++i) buc[i] += buc[i - 1];
        for(int i=len-1;i>=0;--i) SA[--buc[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[SA[0]] = 0;
        for(int i=1;i<len;++i) {
            if(y[SA[i - 1]] == y[SA[i]] && y[SA[i-1] + k] == y[SA[i]] + k) {
                x[SA[i]] = p - 1;
            } else {
                x[SA[i]] = p++;
            }
        }
        if(p >= len) break;
        m = p;
    }
}

int main() {

}