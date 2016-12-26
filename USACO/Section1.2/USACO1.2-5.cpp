/*
ID: ccodera1
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <cstdio>
using namespace std;
int n,s;
bool tf(int k,int b)
{
    int a[50],len=0;
    while (k)
    {
        len++;
        a[len]=k%b;k=k/b;
    }
    for (int i=1;i<=len/2;i++)
        if (a[i]!=a[len-i+1]) return false;
    return true;
}
int main()
{   
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    scanf("%d%d",&n,&s);
    while (n)
    {
        s++;int p=0;
        for (int i=2;i<=10;i++)
            if (tf(s,i))
            {
                p++;
                if (p==2) break;
            }
        if (p==2)
        {
            printf("%d\n",s);
            n--;
        }
    }
    return 0;
}