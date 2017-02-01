#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

const long long MOD = 100000007;

ll reverts(ll p) {
    ll x = 0;
    while(p != 0) {
      x = 10 * x + p % 10;
       p /= 10;
    }
    return x;
}

inline ll fastPow(int x,int p){
    int base = x;
    x = 1;
    while(p){
        if(p & 1){
            x *= base;
        }
        base *= base;
        p >>= 1;
    }
    return x;
}

ll largestPalindrome(int n) {
       if(n == 1) {
        return 9;
    }
    
    ll maxNum = fastPow(10, n) - 1;
    ll maxn = maxNum * maxNum;
    
    ll div = fastPow(10,n);
    ll left = maxn / div;
    ll right = maxn % div;
    
    if(left == reverts(right)) {
        return maxn % MOD;
    }
    if(reverts(left) > right) {
        left --;
    }
    
    maxn = left * div + reverts(left);
    
    while(left >= div / 10) {
        for(long i = maxNum; i > maxn/i; i --) {
            if(maxn % i == 0) {
                return maxn % MOD;
            }
        }
        left --;
        maxn = left * div + reverts(left);
    }
    
    return maxn % MOD;
}

int main(){
    int N;cin>>N;
    cout<<largestPalindrome(N);
    return 0;
}