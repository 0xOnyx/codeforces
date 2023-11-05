#include <iostream>
#include <algorithm>

void solve()
{
	int n;
	std::string s;

	std::cin >> n;
	std::cin >> s;
	std::transform(s.begin(), s.end(), s.begin(), [](char c) -> int
	{
		return (tolower(c));
	});
	s.erase(unique(s.begin(), s.end()), s.end());
	std::cout << ((s == "meow") ? "YES": "NO") << std::endl;
}

int main()
{
	int t;
	std::cin >> t;
	while (t--)
		solve();
}