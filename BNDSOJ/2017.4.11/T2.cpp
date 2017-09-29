#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

string str;
string k;
int main(){
    ios::sync_with_stdio(false);
    int N;cin>>N;
    cin>>str;
    for(int i=0;i<str.length();++i){
        if(!(N & 1)?!(i & 1):(i & 1)){
            k = str[i] + k;
        }else{
            k += str[i];
        }
    }
    cout<<k;
    return 0;
}