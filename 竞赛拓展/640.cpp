
//删除两两相邻的重复数字


#include <iostream>
#include <stack>
using namespace std;

int b[114514],lth = 0,t = 0;
int main()
{
	stack<int> stk;
	int n; cin >> n;
	while(n--)
	{
		int a;cin >> a;
		if(stk.empty()) 
		{
			stk.push(a);
			lth++;
		}
		else
		{
			if(a == stk.top()) 
			{
				stk.pop();
				lth--;
			}
			else 
			{
				stk.push(a);
				lth++;
			}
		}
	}
	if(stk.empty()) cout << "NULL";
	while(!stk.empty())
	{
		b[++t] = stk.top();
		stk.pop();
	}
	for(int i = lth ; i > 0 ; i--) cout << b[i] << ' ';
}
