#include <cstdio>
#include <cstring>

int n, m, q;

namespace first {
  const int kMaxN = 1e3 + 5;
  int matrix[kMaxN][kMaxN];
  void Work() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        matrix[i][j] = (i - 1) * m + j;
    }
    for (int i = 1, x, y; i <= q; i++) {
      scanf("%d%d", &x, &y);
      const int now = matrix[x][y];
      printf("%d\n", now);
      for (int i = y; i < m; i++)
        matrix[x][i] = matrix[x][i + 1];
      for (int i = x; i < n; i++)
        matrix[i][m] = matrix[i + 1][m];
      matrix[n][m] = now;
    }
  }
}

namespace second {
  const int kMaxN = 3e5 + 5;
  int tr[kMaxN];
  inline int lowbit(const int &x) {
    return x & -x;
  }
  void BITAdd(int pos) {
    while (pos <= m) {
      tr[pos]++;
      pos += lowbit(pos);
    }
  }
  int BITQuery(int pos) {
    int ret = 0;
    while (pos) {
      ret += tr[pos];
      pos -= lowbit(pos);
    }
    return ret;
  }
  struct Query {
    int y, ans;
  } query[kMaxN];
  void Work() {
    for (int i = 1; i <= q; i++) {
      scanf("%*d%d", &query[i].y);
      int y = query[i].y + BITQuery(query[i].y);
      y += BITQuery(y) - BITQuery(query[i].y);
      if (y <= m)
        query[i].ans = y;
      else
        query[i].ans = query[y - m].ans;
      printf("%d\n", query[i].ans);
      BITAdd(y);
    }
  }
}

int main() {
  freopen("phalanx10.in", "r", stdin);
  freopen("phalanx.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &q);
  if (n <= 1000) first::Work();
  else second::Work();
  return 0;
}
