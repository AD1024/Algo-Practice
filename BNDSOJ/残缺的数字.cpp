#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int cnt[20];
int p_cnt[20];
const int Pow10[] = {1, 10, 100, 1000, 10000};
vector< pair<int, int> > answer;

inline int read() {
    int a = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0') ch = getchar();
    while(ch >= '0' && ch <= '9') {
        a = a * 10 + ch - '0';
        ch = getchar();
    }
    return a;
}

// Upper = 1100

inline int count_digit(int x) {
    int ans = 0;
    int d;
    while(x) {
        ans += 1;
        d = x % 10;
        p_cnt[d] += 1;
        x /= 10;
    }
    return ans;
}

inline int toInt(vector<int> num) {
    vector<int>::reverse_iterator it = num.rbegin();
    int ans = 0;int cur = 0;
    for(;it!=num.rend();it++) {
        ans += (*it) * Pow10[(cur++)];
    }
    return ans;
}

inline bool ok(int n) {
    memset(p_cnt, 0, sizeof(p_cnt));
    int cnt_digit = count_digit(n);
    for(int i=1;i<n;++i) {
        count_digit(i);
    }
    vector<int> num;
    for(int i=0;i<10;++i) {
        if(p_cnt[i] < cnt[i]) return false;
        for(int _=0;_<p_cnt[i] - cnt[i];++_) {
            num.push_back(i);
        }
    }
    if(num.size() > cnt_digit || num.size() == 0) return false;
    int ans = 0;
    do{
        if(num[0] == 0) continue;
        ans = toInt(num);
        
        if(ans <= n) {
            answer.push_back(make_pair(n, ans));
        }
    }while(next_permutation(num.begin(), num.end()));
    return true;
}

int main() {
    for(int i=0;i<=9;++i) {
        cnt[i] = read();
    }
    for(int i=1;i<=1100;++i) {
        ok(i);
    }
    sort(answer.begin(), answer.end(), [=](pair<int, int> a, pair<int, int> b) -> bool {
        if(a.first != b.first) return a.first < b.first;
        else return a.second < b.second;
    });
    bool f = true;
    for(auto v: answer) {
        f = false;
        printf("%d %d\n", v.first, v.second);
    }
    if(f) {
        puts("NO ANSWER");
    }
    return 0;
}