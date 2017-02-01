//ll - 1
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

//ifstream fin("Lightning1.in");
//ofstream fout("Lightning.out");

char map[1005][1005];
bool visit[1005][1005];
int n, m, c, ans = 0, xx, yy;

void dfs(int x, int y, int k)
{
	visit[x][y] = 1;
	if(map[x][y] == '#')
	{
		map[x][y] = '*';
	}
	else if(map[x][y] == '.')
		map[x][y] = '*';
	if(k == 0)
	{
		if(x - 1 >= 0 && x - 1 < n && y >= 0 && y < m) dfs(x - 1, y, 1);
		if(x + 1 >= 0 && x + 1 < n && y >= 0 && y < m) dfs(x + 1, y, 2);
		if(x >= 0 && x < n && y + 1 >= 0 && y + 1 < m) dfs(x, y + 1, 3);
		if(x >= 0 && x < n && y - 1 >= 0 && y - 1 < m) dfs(x, y - 1, 4);
	}
	if(k == 1)
		if(x - 1 >= 0 && x - 1 < n && y >= 0 && y < m)
			dfs(x - 1, y, k);
	if(k == 2)
		if(x + 1 >= 0 && x + 1 < n && y >= 0 && y < m)
			dfs(x + 1, y, k);
	if(k == 4)
		if(x >= 0 && x < n && y - 1 >= 0 && y - 1 < m)
			dfs(x, y - 1, k);
	if(k == 3)
		if(x >= 0 && x < n && y + 1 >= 0 && y + 1 < m)
			dfs(x, y + 1, k);
}


int main()
{
	freopen("Lightning9.in","r",stdin);
	cin>>n>>m>>c;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
		{
			cin>>map[i][j];
		}
	for(int i = 0;i < c;i++)
	{
		cin>>xx>>yy;
		map[xx][yy] = '.';visit[xx][yy] = 0;
		dfs(xx, yy, 0);
	}
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
		{
			if(map[i][j] == '#')
				ans++;
		}
	cout<<ans<<endl;
	return 0;
}
