#include <bits/stdc++.h>

void solve(void)
{
	int 		r;
	int			n;
	std::string	s;

	std::cin >> n;
	std::cin >> s;
	r = n - 1;
	for (int i = 1; i + 1 < n; i++)
	{
		if (s[i - 1] == s[i + 1])
			r--;
	}
	std::cout << r << std::endl;
}


int	main()
{
	int t;

	std::cin >> t;
	while (t--)
		solve();
}