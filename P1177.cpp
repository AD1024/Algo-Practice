#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

long long a[1000001];
// /*
// void Qsort(int low, int high)
// {
//     if(low >= high)
//     {
//         return;
//     }
//     int first = low;
//     int last = high;
//     int key = a[first];/*用字表的第一个记录作为枢轴*/
// /*
//     while(first < last)
//     {
//         while(first < last && a[last] >= key)
//         {
//             --last;
//         }
//
//         a[first] = a[last];/*将比第一个小的移到低端*/
//
//         while(first < last && a[first] <= key)
//         {
//             ++first;
//         }
//
//         a[last] = a[first];
// /*将比第一个大的移到高端*/
//     }
//     a[first] = key;/*枢轴记录到位*/
//     Qsort(low, first-1);
//     Qsort(first+1, high);
// }
// */

int readInt(){
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n'){
        a *= 10;
        a += ch - '0';
    }
    return a;
}
int main(){
  int n;
  cin>>n;
  list<int> L;
  for(int i=0;i<n;i++){
    int t;
    t=readInt();
    L.push_back(t);
  }
  L.sort();
  list<int>::iterator it;
  for(it=L.begin();it!=L.end();it++){
    cout<<*it<<" ";
  }
  return 0;
}
