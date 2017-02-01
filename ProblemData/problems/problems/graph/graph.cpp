#include <cassert>
#include <cstdio>
#include <cstring>
#include <queue>

const int N = 100000;
const int M = 100000;

int n, edge_count, first_edge[N], to[M], next_edge[M], answer[N];

void add_edge(int u, int v) {
    to[edge_count] = v;
    next_edge[edge_count] = first_edge[u];
    first_edge[u] = edge_count ++;
}

int main() {
    int m;
    assert(scanf("%d%d", &n, &m) == 2);
    assert(1 <= n && n <= 100000);
    assert(1 <= m && m <= 100000);
    edge_count = 0;
    memset(first_edge, -1, sizeof(first_edge));
    for (int i = 0; i < m; ++ i) {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        a --, b --;
        add_edge(b, a);
    }
    memset(answer, -1, sizeof(answer));
    for (int i = n - 1; i >= 0; -- i) {
        if (answer[i] == -1) {
            answer[i] = i;
            std::queue <int> queue;
            queue.push(i);
            while (!queue.empty()) {
                int u = queue.front();
                queue.pop();
                for (int iter = first_edge[u]; iter != -1; iter = next_edge[iter]) {
                    int v = to[iter];
                    if (answer[v] == -1) {
                        answer[v] = i;
                        queue.push(v);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", answer[i] + 1, " \n"[i == n - 1]);
    }
    return 0;
}
