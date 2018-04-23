#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

inline bool leap(int x) {
    return (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0));
}

const int days[3][20] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
                      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

struct Date{
    int yy, mm, dd;
    int week;
    bool isleap;
    Date(){}
    Date(int y, int m, int d, int wk) {
        yy = y;
        mm = m;
        dd = d;
        week = wk;
        isleap = leap(yy);
    }

    void next_year() {
        yy += 1;
        isleap = leap(yy);
    }

    void next_month() {
        mm += 1;
        if(mm > 12) {
            next_year();
            mm = 1;
        }
    }

    void next_day() {
        dd += 1;
        week = week + 1 > 7 ? 1 : week + 1;
        if(dd > days[isleap][mm - 1]) {
            next_month();
            dd = 1;
        }
    }
};

inline void work(Date a, Date b) {
    Date t = Date(b.yy, b.mm, b.dd, b.week);
    bool f = false;
    if(a.yy > b.yy) {
        swap(a, b);
        f = true;
    } else if(a.yy == b.yy) {
        if(a.mm > b.mm) {
            swap(a, b);
            f = true;
        } else if(a.mm == b.mm) {
            if(a.dd > b.dd) {
                swap(a, b);
                f = true;
            }
        }
    }
    int cnt = 0;
    while(a.yy != b.yy || a.mm != b.mm || a.dd != b.dd) {
        cnt += 1;
        a.next_day();
    }
    int week = 7;
    cnt %= 7;
    if(f) {
        while(cnt--) {
            week = week - 1 < 1 ? 7 : week - 1;
        }
    } else {
        while(cnt--) {
            week = week + 1 > 7 ? 1 : week + 1;
        }
    }
    t.week = week;
    int m = t.mm, d = t.dd, y = t.yy;
    t.next_day();
    while(1) {
        if(t.yy != y && t.dd == d && t.mm == m && t.week == week) break;
        t.next_day();
    }
    printf("%d\n", t.yy);
}

int main() {
    int T;
    scanf("%d", &T);
    int y, m, d;
    Date p = Date(2017, 8, 6, 7);
    while(T--) {
        scanf("%d-%d-%d", &y, &m, &d);
        Date k = Date(y, m, d, -1);
        work(p, k);
    }
    return 0;
}