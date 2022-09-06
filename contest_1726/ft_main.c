#include <stdio.h>
#include <stdlib.h>

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	resolve(int *tab, int tab_size)
{
	int i;
	int	res;
	
	i = 0;
	while (i < tab_size)
	{
		scanf("%d", tab + i);
		i++;
	}
	res = tab[tab_size - 1] - tab[0];
	i = 1;
	while (i < tab_size)
	{
		res = max(res, tab[i] - tab[0]);
		i++;
	}
	i = 0;
	while (i < tab_size - 1)
	{
		res = max(res, tab[tab_size - 1] - tab[i]);
		i++;
	}
	i = 0;
	while (i < tab_size - 1)
	{
		res = max(res, tab[i] - tab[i + 1]);
		i++;
	}
	return (res);
}

int main(void)
{
	int	*tab;
	int		len_test;
	int		len_tab;
	int		test_i;
	int		res;

	test_i = 0;
	scanf("%d\n", &len_test);
	while (test_i < len_test)
	{
		scanf("%d\n", &len_tab);
		tab = (int *)calloc(sizeof(int), len_tab);
		res = resolve(tab, len_tab);
		printf("%d\n", res);
		free(tab);
		test_i++;
	}
	return (0);
}