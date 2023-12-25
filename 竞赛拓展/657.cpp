//清点代码库


#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n,m;
set<ull>st;
ull hs[105];
int cnt[1005];
map<vector<int>, int> mmp;
vector<vector<int>> ans;
ull findhash(int m, vector<int> a)
{	
	ull hashval = 0;
	for(int i = 0; i <= m - 1; i++)
	{
		hashval = (hashval * 1031 + (ull)a[i]) % 131;
	}
	return hashval;
}
bool cmp(vector<int> a, vector<int> b)
{
	ull aa = 0; ull bb = 0;
	if(a[0] > b[0]) return a > b;
	else if(a[0] < b[0]) return a > b;
	for(int i = 1; i <= m; i++)
	{
		aa = aa*131 + a[i];
		bb = bb*131 + b[i];
	}
	return a < b;
}
int main()
{
	cin >> n >> m;
	while(n--)
	{
		vector<int> a;
		for(int i = 1; i <= m; i++)
		{
			int t; cin >> t;
			a.push_back(t);
		}
		ull has = findhash(m, a);
		if(st.find(has) == st.end())
		{
			mmp.insert(pair<vector<int>,int>(a,1));
			st.insert(has);
		}
		else mmp[a]++;
	}
	cout << mmp.size() << endl;
	for(auto it = mmp.begin(); it != mmp.end(); it++)
	{
		vector<int> b;
		b.push_back(it->second);
		for(int i = 0; i <= m - 1; i++) b.push_back(it->first[i]);
		ans.push_back(b);
	}
	sort(ans.begin(), ans.end(), cmp);
	for(auto &b : ans)
	{
		for(int i = 0; i <= m; i++) cout << b[i] << ' ';
		cout << '\n';
	}
}
