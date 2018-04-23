#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll a[201000];

ll sum;

int N;
ll upper, t;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;++i) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if(sum & 1) {
        upper = (sum >> 1) + 1;
    } else {
        upper = sum >> 1;
    }
    for(int i=1;i<=N;++i) {
        t += a[i];
        if(t >= upper) {
            printf("%d\n", i);
            exit(0);
        }
    }
    return 0;
}