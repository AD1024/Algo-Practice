#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

int map[310][310];
bool vis[310][310];

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int N;

inline int read() {
    int a = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        a = a * 10 + ch - '0';
        ch = getchar();
    }
    return a;
}

struct Pos {
    int x, y;
    int step;

    Pos() {}

    Pos(int xx, int yy, int s) {
        x = xx;
        y = yy;
        step = s;
    }
};

queue<Pos> que;

inline bool valid(int nx, int ny) {
    return nx >= 0 && nx <= 300 && ny >= 0 && ny <= 300;
}

#define INF 0x3f3f3f3f

int main() {
    cin >> N;
    int x, y, t;
    memset(map, INF, sizeof(map));
    for (int i = 1; i <= N; ++i) {
        x = read();
        y = read();
        t = read();
        map[x][y] = min(t, map[x][y]);
        if (x > 0) {
            map[x - 1][y] = min(t, map[x - 1][y]);
        }
        if (y > 0) {
            map[x][y - 1] = min(t, map[x][y - 1]);
        }
        map[x + 1][y] = min(t, map[x + 1][y]);
        map[x][y + 1] = min(t, map[x][y + 1]);
    }
    vis[0][0] = true;
    if (map[0][0] > 0) {
        que.push(Pos(0, 0, 0));
    }else{
    	puts("-1");return 0;
    }
    Pos k;
    int nx, ny, cx, cy;
    while (!que.empty()) {
        k = que.front();
        que.pop();
        cx = k.x;
        cy = k.y;
        if (map[cx][cy] == INF) {
            cout << k.step << endl;
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (!vis[nx][ny] && map[nx][ny] > k.step + 1 && (valid(nx, ny) || nx >300 || ny > 300)) {
                vis[nx][ny] = true;
                que.push(Pos(nx, ny, k.step + 1));
            }
        }
    }
    puts("-1");
    return 0;
}