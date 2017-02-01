#include <cstdio>
#include <iostream>

const int N = 100000;

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    long long answer = 0;
    for (int i = 0; i < n; ++ i) {
        int sum = 0;
        for (int j = i; j < n; ++ j) {
            sum ^= a[j];
            answer += sum;
        }
    }
    std::cout << answer << std::endl;
    return 0;
}
