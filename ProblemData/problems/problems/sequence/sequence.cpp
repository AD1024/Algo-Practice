#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int n;
    assert(scanf("%d", &n) == 1);
    assert(1 <= n && n <= 100000);
    int count[16];
    memset(count, 0, sizeof(count));
    for (int i = 0, sum = 0; i < n; ++ i) {
        int ai;
        assert(scanf("%d", &ai) == 1);
        assert(0 <= ai && ai < 1 << 16);
        sum ^= ai;
        for (int j = 0; j < 16; ++ j) {
            count[j] += sum >> j & 1;
        }
    }
    long long answer = 0;
    for (int i = 0; i < 16; ++ i) {
        answer += (long long)count[i] * (n + 1 - count[i]) << i;
    }
    std::cout << answer << std::endl;
    return 0;
}
