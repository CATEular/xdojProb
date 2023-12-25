//BFS旅行

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
typedef struct{
	bool a[N][N];
	int vm,am;
}Graph;
Graph G;
bool vis[N];
queue<int> q;
queue<int>qq;
bool vv[N];
void bfs()
{
	q.push(1);
	qq.push(1);
	while(!q.empty())
	{
		int u = q.front();q.pop();
		vis[u] = true;
		if(u == G.vm) break;
		for(int v = 1; v <= G.vm; v++)
			if(G.a[u][v] && !vis[v]) 
			{
				q.push(v);
				qq.push(v);
			}
	}
}

int main()
{
	memset(vis, 0, sizeof vis);
	memset(G.a, 0, sizeof G.a);
	
	cin >> G.vm >> G.am;
	for(int i = 1, u, v; i <= G.am; i++)
	{
		cin >> u >> v;
		G.a[u][v] = G.a[v][u] = true;
	}
	bfs();
	if(vis[G.vm])
	{
		cout << "YES" << endl;
		while(!qq.empty())
		{
			if(!vv[qq.front()])
			{
				cout << qq.front() << ' ';
				vv[qq.front()] =true;
			}
			if(qq.front() == G.vm) break;
			qq.pop();
		}	
	}
	else
	{
		cout << "NO" << endl;
		while(!qq.empty())
		{
			if(!vv[qq.front()])
			{
				cout << qq.front() << ' ';
				vv[qq.front()] = true;
			}
			if(qq.front() == G.vm) break;
			qq.pop();
		}
	}
	
	
	return 0;
}
