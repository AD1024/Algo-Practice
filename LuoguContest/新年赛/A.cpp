#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1001000;
const ll MOD = 666623333;

ll L, R, t;
bool vis[MAXN];
ll ans = 0;
vector<int> ep[MAXN];
ll cur;

inline void init(ll l,ll r){
    t = sqrt(r) + 10;
    for (ll i = 2; i <= t; i++) {
        if (vis[i]) continue;
        for (ll j = i << 1; j <= t; j += i){
            vis[j] = 1;
        }
        ll lower = i * (l / i);
        ll upper = i * (r / i + 1);
        // cout<<lower<<" "<<upper<<endl;
        for (ll j = lower; j <= upper; j += i) {
            if (l <= j && j <= r && j > i){
                ep[j - l].push_back(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> L >> R;
    init(L,R);
    // for(int i=1;i<=R-L;++i){
    //     cout<<i<<": ";
    //     for(int j=0;j<ep[i].size();++j){
    //         cout<<ep[i][j]<< " ";
    //     }
    //     puts("");
    // }
    for (ll i = 0; i <= R-L; i++) {
        cur = i+L;
        ll t = i+L;
        ll k = cur;
        for (int j = 0; j < ep[i].size(); j++) {
            int c = ep[i][j];
            while (!(cur % c)){
                cur /= c;
            }
            t = t * (c - 1) / c;
        }
        if (cur > 1){
            t = t * (cur - 1) / cur;
        }
        t = (k - t)%MOD;
        ans += t;
        // ans %= MOD;
    }
    ans %= MOD;
    cout<<ans<<"\n";
    return 0;
}