//悄悄关注

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1005;
struct People{
	char name[5];
	ull hashv;
	int likes;
}p1[N],p2[N];
double sum;
int cnt;
ull findhash(People p)
{
	return 13*13*13*p.name[0] + 13*13*p.name[1] + 13*p.name[2] + p.name[3];
}

int main()
{
	int n; cin >> n;
	for(int i = 1; i <=n; i++)
	{
		cin >> p1[i].name;
		p1[i].hashv = findhash(p1[i]);
	}
	int m; cin >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> p2[i].name >> p2[i].likes;
		p2[i].hashv = findhash(p2[i]);
		sum += p2[i].likes;
	}
	double ave = sum*1.0 / m;
	int passnum = 0;
	bool flag = false;
	for(int i = 1; i <= m; i++)
	{	
		int cntt = 0;
		for(int j  = 1; j <= n; j++)
			if(p2[i].hashv == p1[j].hashv) break;
			else cntt++;	
		
		if(cntt == n)
		{
			passnum++;
			flag = true;
			if(p2[i].likes > ave) 
			{
				cout << p2[i].name << endl;
				cnt++;
			}
		}
	}
	if(!cnt) cout << passnum;
	return 0;
}

