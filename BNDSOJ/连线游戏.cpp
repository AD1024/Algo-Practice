#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;
#define eps 1e-7

#define MAXN 40040
#define INF 0x3f3f3f3f

double k[MAXN];
int N;
int x[400], y[400];
int cnt;
int ans;

int main() {
    cin>>N;
    for (int i = 0; i <N; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (abs(x[i] - x[j]) > eps) {
                k[cnt++] = (double(y[i] - y[j])) / (double(x[i] - x[j]));
            } else k[cnt++] = INF;
        }
    }
    sort(k, k + cnt);
    ans = 1;
    for (int i = 1; i < cnt; i++) {
        if (k[i] - k[i - 1] > eps) {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}