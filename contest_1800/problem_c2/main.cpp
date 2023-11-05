#include <bits/stdc++.h>

void solve(void)
{
	int l;
	long long r;

	r = 0;
	std::cin >> l;
	std::priority_queue<int> buff;
	while (l--)
	{
		int c;

		std::cin >> c;
		if (c > 0)
			buff.push(c);
		else
		{
			if (buff.empty())
				continue ;
			r += static_cast<long long>(buff.top());
			buff.pop();
		}
	}
	std::cout << r << std::endl;
}

int main(void)
{
	int t;

	std::cin >> t;
	while (t--)
		solve();
}