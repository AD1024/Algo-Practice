#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

inline int gcd(int x,int y) {
    while(x^=y^=x^=y%=x);
    return y;
}

int N, ans;

int main() {
    ans = 1;
    ios::sync_with_stdio(false);
    cin>>N;
    N -= 1;
    int g, cur;
    cin>>g;int p;
    while(N--) {
        cin>>cur;p = gcd(cur, g);
        if(p != 1) {
            ans += 1;
            g = p;
        }
    }
    cout<< ans;
    return 0;
}