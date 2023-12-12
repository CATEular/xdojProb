
//迷宫寻路

#include <bits/stdc++.h>
using namespace std;
bool p[30][30],vis[30][30]; 
int d[30][30];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int m,n;
bool inmap(int x, int y)
{
	return 0 <= x && x < m && 0 <= y && y < n;
}
void bfs(int sx, int sy)
{
	queue< pair<int,int> > q;
	memset(d, 0x3f, sizeof d);
	d[sx][sy] = 0;
	vis[sx][sy] = true;
	q.push({sx,sy});

	while(q.size())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if(inmap(nx,ny) && !p[nx][ny] && !vis[nx][ny])
			{
				d[nx][ny] = d[x][y] + 1;
				vis[nx][ny] = true;
				q.push({nx,ny});
			}
		}
	}
}
int main()
{
 	cin >> m >> n;
	int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
	for(int i = 0; i < m ;i++)
		for(int j = 0 ; j < n ; j++) cin >> p[i][j];
	bfs(sx, sy);
	
	cout << d[ex][ey];
	return 0;
}
