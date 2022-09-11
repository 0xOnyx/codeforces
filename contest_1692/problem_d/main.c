#include <stdio.h>

void	add(int *h, int *m, int iter)
{
	*h += iter / 60;
	*m += iter % 60;
	if (*m >= 60)
	{
		*h += *m / 60;
		*m = *m % 60;
	}
}

int	is_palindr(int h, int m)
{
	int	tmp;

	tmp = m;
	m = tmp / 10;
	m += tmp % 10 * 10;
	if (h == m)
		return (1);
	return (0);
}

int	get_palindr(int h, int m, int iter)
{
	int	res;

	res = 0;
	while (h < 24 && m < 60)
	{
		if (is_palindr(h, m))
		{
			printf("%d %d:%d\n", is_palindr(h, m), h, m);
			res++;
		}
		add(&h, &m, iter);
	}
	return (res);
}

int	main(void)
{
	int	len_test_case;
	int	current_test_case;
	int	iter;
	int	h;
	int	m;
	
	scanf("%d", &len_test_case);
	current_test_case = 0;
	while(current_test_case < len_test_case)
	{
		scanf("%d:%d", &h, &m);
		scanf("%d", &iter);
		printf("%d\n", get_palindr(h, m, iter));
		current_test_case++;
	}
	return (0);
}
