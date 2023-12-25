//A+B问题

#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N],b[N];
int i,j,cnt;
bool flag;
int main()
{
	int n,m; cin >> n >> m;
	while(n > 0)
	{
		a[i] = n % 2;
		i++;
		n /= 2;
	}
	while(m > 0)
	{
		b[j] = m % 2;
		j++;
		m /= 2;
	}
	for (int k = 0; k < N; k++)
	{
		if(a[k] == b[k])
		{
			if(a[k] == 1)
			{
				flag = true;
				cnt++;
			}
			else
			{
				if(flag) flag = false;
			}
		}
		else
		{
			if(flag)
				cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}
