#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

string s;
int N, A, B;
int ans = 0;
int pre = 1;
bool place;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> A >> B;
    cin >> s;
    for(int i=0;i<s.size();++i) {
        place = false;
        if(A == 0 && B == 0) break;
        if(s[i] == '*') continue;
        else {
            if(i == 0) {
                if(A > B) {
                    A--;pre = 1;place = true;
                } else {
                    B--;pre = 0;place = true;
                }
            } else {
                if(s[i-1] == '*') {
                    if(A > B) {
                        A--;pre = 1;place = true;
                    } else {
                        B--;pre = 0;place = true;
                    }
                } else {
                    if(pre) {
                        if(B) {
                            B--;pre = 0;place = true;
                        }
                    } else {
                        if(A) {
                            A--;pre = 1;place = true;
                        }
                    }
                }
            }
        }
        if(!place) {
            if(A > B) pre = 0;
            else pre = 1;
        } else {
            ans += 1;
        }
    }
    cout << ans;
    return 0;
}