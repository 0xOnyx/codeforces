#include <stdio.h>
#include <string.h>

void	new_contest(int	tabs_problems[27])
{
	char	problem_resolve;
	int		len_problem;
	int		problem_i;
	int		res;
	int		pos;

	res = 0;
	problem_i = 0;
	scanf("%d\n", &len_problem);
	while (problem_i < len_problem)
	{
		scanf("%c\n", &problem_resolve);
		problem_resolve -= 'A';
		pos = (unsigned int)problem_resolve;
		if (tabs_problems[pos] == 0)
			res += 2;
		if (tabs_problems[pos] > 0)
			res += 1;
		tabs_problems[pos]++;
		problem_i++;
	}
	printf("%d\n", res);
}

int		main(void)
{
	int		tabs_problems[27];
	int		len_test_case;
	int		test_case_i;
	
	test_case_i = 0;
	scanf("%d\n", &len_test_case);
	while (test_case_i < len_test_case)
	{
		memset((void *)tabs_problems, 0, sizeof(int) * 27);
		new_contest(tabs_problems);
		test_case_i++;
	}
	return (0);
}