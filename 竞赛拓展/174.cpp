
//分配宝藏

#include<bits/stdc++.h>
using namespace std;
int dp[205][40005],w[205];
int sum, suma;
int main()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i];
		sum += w[i];
	}
	for(int i = 1; i <=n; i++)
	{
		if(w[i] > sum/2) 
		{
			dp[n][sum/2] = sum - w[i];
			break;
		}
		
		for(int j = 0; j <= sum /2; j++)
		{
			if(w[i] > j) dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j] , dp[i - 1][j - w[i]] + w[i]);
		}
	}
	suma = dp[n][sum/2];
	cout << sum - 2*suma;
	return 0;
}
