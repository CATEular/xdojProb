// 背包问题2

#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+1;
const int N = 1e6+5;
typedef long long ll;

ll v[101],dp[N],V;
int c[101],n,sum;
int main() 
{
	memset(dp, M, sizeof dp);
    dp[0] = 0;
	cin >> n >> V;
    for (int i = 0; i < n; i ++) cin >> v[i];
    for (int i = 0; i < n; i ++) 
    {
        cin >> c[i];
        sum += c[i];
    }
    for (int i = 0; i < n; i ++) 
    {
        for (int j = sum; j >= c[i]; j--) 
        {
            ll minn = dp[j - c[i]] + v[i];
            if (minn < dp[j]) dp[j] = minn;
        }
    }
    for (int i = sum; i >= 0; i --) 
    {
        if (dp[i] <= V) 
        {
            cout << i ;
            break;
        }
    }
    return 0;
}
