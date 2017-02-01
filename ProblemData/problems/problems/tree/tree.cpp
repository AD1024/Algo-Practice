#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 100000;

int n, k, edge_count, first_edge[N], to[N << 1], next_edge[N << 1];

void add_edge(int u, int v) {
    to[edge_count] = v;
    next_edge[edge_count] = first_edge[u];
    first_edge[u] = edge_count ++;
}

int parent[N];

int find(int u) {
    if (parent[u] == -1) {
        return u;
    }
    return parent[u] = find(parent[u]);
}

int size[N];

bool check() {
    if (n % k != 0) {
        return false;
    }
    memset(parent, -1, sizeof(parent));
    std::vector <int> queue;
    queue.push_back(0);
    for (int head = 0; head < (int)queue.size(); ++ head) {
        int u = queue[head];
        for (int iter = first_edge[u]; iter != -1; iter = next_edge[iter]) {
            int v = to[iter];
            if (v != parent[u]) {
                parent[v] = u;
                queue.push_back(v);
            }
        }
    }
    memset(size, 0, sizeof(size));
    int count = 0;
    for (int i = n - 1; i >= 0; -- i) {
        int u = queue[i];
        size[u] ++;
        if (parent[u] != -1) {
            size[parent[u]] += size[u];
        }
        count += size[u] % k == 0;
    }
    return count == n / k;
}

int main() {
    int tests;
    assert(scanf("%d", &tests) == 1);
    assert(1 <= tests && tests <= 10);
    while (tests --) {
        assert(scanf("%d%d", &n, &k) == 2);
        assert(1 <= n && n <= 100000);
        assert(1 <= k && k <= 100000);
        edge_count = 0;
        memset(first_edge, -1, sizeof(first_edge));
        memset(parent, -1, sizeof(parent));
        for (int i = 0; i < n - 1; ++ i) {
            int a, b;
            assert(scanf("%d%d", &a, &b) == 2);
            assert(1 <= a && a <= n);
            assert(1 <= b && b <= n);
            a --, b --;
            assert(find(a) != find(b));
            parent[find(a)] = find(b);
            add_edge(a, b);
            add_edge(b, a);
        }
        puts(check() ? "YES" : "NO");
    }
    return 0;
}
