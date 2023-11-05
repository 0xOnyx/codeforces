#include <bits/stdc++.h>

const int N = 26;

void solve()
{
	int res = 0;
	int l;
	int k;
	std::string s;
	std::vector<int>big (N, 0);
	std::vector<int>small(N, 0);

	std::cin >> l >> k;
	std::cin >> s;
	for (auto &i : s)
	{
		if (isupper(i))
			big[i - 'A']++;
		else
			small[i - 'a']++;
	}
	for (int i = 0; i < N; i++)
	{
		int pairs = std::min(big[i], small[i]);
		res += pairs;
		big[i] -= pairs;
		small[i] -= pairs;
		int add = std::min(k, std::max(big[i], small[i]) / 2);
		res += add;
		k -= add;
	}
	std::cout << res << std::endl;
}

int main()
{
	int t;

	std::cin >> t;
	while (t--)
		solve();
	return (0);
}