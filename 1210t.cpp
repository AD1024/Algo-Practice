#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <iomanip>
typedef long long ll;
typedef unsigned long long llu;
using namespace std;

vector<int> prime;
void init()
{
    int num[150000]= {0};
    for(int i=2; i*i<10000+10; i++)
        for(int j=i*i; j<10000+10; j+=i)
            num[j]=1;
    for(int i=2; i<10000+10; i++)
        if(!num[i])
            prime.push_back(i);
}

int main()
{
    init();
    int x;
    while(cin>>x && x)
    {
        int l=0, r=0, sum=prime[0];
        int ans=0;
        while(l<=r && prime[r]<=x && r<prime.size())
        {
            if(sum==x)
            {
                ans++;
                sum-=prime[l++];
            }
            else if(sum>x)
                sum-=prime[l++];
            else
                sum+=prime[++r];
        }
        cout<<ans<<endl;
    }
    return 0;
}