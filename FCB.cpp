#include <iostream>
using namespace std;
const int N=10;
int n, m;
int rcd[N]={1,2,3,4,5,6,7,8,9}; int used[N];
int num[N];
void unrepeat_combination(int l, int p){
int i;
for (i=0; i<l; i++) cout<<rcd[i]<<" ";
cout<<endl;
for (i=p; i<m; i++)
  if (used[i] > 0) {
    used[i]--;
    rcd[l] = num[i];
    unrepeat_combination(l+1, i);
    used[i]++;
  }
}
int main() {
int i, j, val; cin>>n;
m = 0;
for (i=0; i<n; i++) {
  cin>>val;
for (j=0; j<m; j++)
  if (num[j] == val) {
    used[j]++; break;
  }
}
  if (j == m)
  num[m] = val, used[m++] = 1;
  unrepeat_combination(0, 0);
  return 0;
}
