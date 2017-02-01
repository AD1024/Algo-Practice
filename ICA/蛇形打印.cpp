#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[10010];

int main() {
    int N, i, j, k, f;cin>>N;
    for (i = j = k = 0; i < N; i++, j++) {
        k += (i + 1);
        a[i * N] = (j % 2) ? k : k - i;
    }
    for (i = 1; i < N; i++, j++) {
        k += (N - i);
        a[(N - 1) * N + i] = (j % 2) ? k : k - (N - i - 1);
    }
    for (i = f = 1; i < N; i++, f = -f)
        for (j = 0; j < N - 1; j++) {
            a[j * N + i] = (j % 2) ? (a[(j + 1) * N + (i - 1)] + f) : (a[(j + 1) * N + (i - 1)] - f);
        }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
          cout<<a[i*N+j]<<" ";
        }
        puts("");
    }
}