#include <stdio.h>

int	main(void)
{
	int	len_test;
	int	current_test;
	int	tab[4];
	int	res;
	int	i;

	current_test = 0;
	scanf("%d\n", &len_test);
	while (current_test < len_test)
	{
		res = 0;
		scanf("%d%d%d%d", 
			(int *)tab,
			(int *)tab + 1,
			(int *)tab + 2,
			(int *)tab + 3);
		i = 1;
		while (i < 4)
		{
			if (tab[0] < tab[i])
				res++;
			i++;
		}
		printf("%d\n", res);
		current_test++;
	}
	return (0);
}
