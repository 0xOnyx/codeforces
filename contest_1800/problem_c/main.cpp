#include <bits/stdc++.h>

void solve(void)
{
	int l;
	long long r;

	r = 0;
	std::cin >> l;
	std::vector<int> buff;
	while (l--)
	{
		int c;

		std::cin >> c;
		if (c > 0)
			buff.push_back(c);
		else
		{
			if (buff.empty())
				continue ;
			std::sort(buff.begin(), buff.end());
			r += static_cast<long long>(buff.back());
			buff.pop_back();
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