#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int s, t, w;

bool carry = false;
string x;

inline string work() {
    if(x[0] - 'a' == t - w) return "";
    int p = x.length() - 1;
    while(x[p] - 'a' == t - w + p) --p;
    x[p] += 1;
    for(int i=p+1;i<x.length();++i) {
        x[i] = x[p] - p + i;
    }
    cout<<x<<"\n";
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> s >> t >> w >> x;
    int T = 5;
    while(T--) {
        x = work();
        if(x == "") break;
    }
    return 0;
}