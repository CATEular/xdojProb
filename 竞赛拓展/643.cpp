
//分蛋糕

#include <bits/stdc++.h>
using namespace std;
int a[1000+10];
queue<int> q;
int ans;
int main()
{
	int n, k; cin >> n >> k;
	for(int i = n ; i >= 1 ; i--)
	{
		int t; cin >> t;
		q.push(t);
	}
	while(!q.empty())
	{
		ans++;
		int kk = k;
		while(kk > 0 && !q.empty())
		{
			kk -= q.front(); 
			q.pop();
		}
	}
	cout << ans;
	return 0;
}
