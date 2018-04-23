#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 201000
#define ll long long

ll g[5][MAXN];
int ptr[5];
int cptr[5];
ll ans;
int N;

template<typename T>
inline auto Abs(T x) -> decltype(x) {
    return x < 0?-x:x;
}

inline int tr(char ch) {
    switch(ch) {
        case 'B': return 1;
        case 'R': return 2;
        case 'P': return 3;
    }
}

void dfs(int dep, int cur, ll sum) {
    if(dep == N - 1) {
        ans += sum;
    } else {
        if(cptr[cur] > ptr[cur]) {
            ans += sum;
            return;
        }
        cout<<dep<<" "<<cur<<" "<<sum<<endl;
        int cpos = g[cur][cptr[cur]++];
        if(cur == 1 || cur == 2) {
            // cout << cptr[cur] << endl;
            if(cptr[cur] <= ptr[cur] && cptr[3] <= ptr[3]) {
                cout << Abs(g[cur][cptr[cur]] - cpos) << endl;
                if(Abs(g[cur][cptr[cur]] - cpos) < Abs(g[cur][cptr[3]] - cpos)) {
                    return dfs(dep + 1, cur, sum + Abs(g[cur][cptr[cur]] - cpos));
                } else {
                    return dfs(dep + 1, 3, sum + Abs(g[cur][cptr[3]++] - cpos));
                }
            } else if(cptr[cur] <= ptr[cur]){
                return dfs(dep + 1, cur, sum + Abs(g[cur][cptr[cur]] - cpos));
            } else if(cptr[3] <= ptr[3]) {
                return dfs(dep + 1, 3, sum + Abs(g[cur][cptr[3]++] - cpos));
            } else {
                ans += sum;return;
            }
        } else {
            int minm = 0x3f3f3f3f;
            int to = cur;
            for(int i=1;i<=3;++i) {
                if(cptr[i] <= ptr[i] && Abs(g[i][cptr[i]] - cpos) < minm) {
                    minm = Abs(g[i][cptr[i]] - cpos);
                    to = i;
                }
            }
            if(minm == 0x3f3f3f3f) {
                ans += sum;return;
            }
            return dfs(dep + 1, to, sum + Abs(g[to][cptr[to]++] - cpos));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int p;char ch;
    cin >> N;
    for(int i=0;i<N;++i) {
        cin >> p >> ch;
        switch(ch) {
            case 'B': g[tr(ch)][++ptr[tr(ch)]] = p;break;
            case 'R': g[tr(ch)][++ptr[tr(ch)]] = p;break;
            case 'P': g[tr(ch)][++ptr[tr(ch)]] = p;break;
        }
    }
    cptr[1] = cptr[2] = cptr[3] = 1;
    dfs(0, 1, 0);
    dfs(0, 2, 0);
    dfs(0, 3, 0);
    printf("%lld", ans);
    return 0;
}