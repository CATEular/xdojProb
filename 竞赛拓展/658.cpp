//DFS旅行

#include <iostream>
#include <cstdio>
#include <stack> 
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int MaxVnum=1010;

stack<int> route;
vector<int> ret;

typedef struct{
	int a[MaxVnum][MaxVnum];
	int vexnum,arcnum;
}Graph;

Graph G;
bool visited[MaxVnum];
bool arrived = false;

void dfs(int u)
{	if(arrived==false)
		route.push(u);
	visited[u]=true;
	
	if(u==G.vexnum){
		arrived = true;
		return;
	}
	
	for(int v=1;v<=G.vexnum;v++) {
		
		if(G.a[u][v]==1&&visited[v]==false){
			dfs(v);
		}
		
	}
	
	
	return;
}
 
int main()
{
	memset(visited,0,sizeof(visited));
	memset(G.a,0,sizeof(G.a));
	
	scanf("%d%d",&G.vexnum,&G.arcnum); 
	
	for(int i=1,u,v;i<=G.arcnum;i++){
		scanf("%d%d",&u,&v);
		G.a[u][v]=G.a[v][u]=1;
	}
	
	dfs(1);
	if(visited[G.vexnum]){
		puts("YES");
	
	}
	else{
		puts("NO");
	}
	
	
	while (!route.empty()) {
		ret.push_back(route.top());
		route.pop();
	}
	for (int i = ret.size() - 1; i >= 0; --i) {
		cout << ret[i] << " ";
	}
}
