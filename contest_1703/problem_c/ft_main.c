#include <stdio.h>
#include <stdlib.h>

void	process_step(char *tab_step, int *nbr)
{
	while (*tab_step)
	{
		if (*tab_step == 'U')
			*nbr = (*nbr <= 0) * (9) + (*nbr > 0) * (*nbr - 1);
		if (*tab_step == 'D')
			*nbr = (*nbr >= 9) * (0) + (*nbr < 9) * (*nbr + 1);
		tab_step++;
	}
}

void	resolve_cypher(int *tab_cypher, int len_cypher)
{
	int		cypher_i;
	int		len_step;
	int		step_i;
	char	*tab_step;

	cypher_i = 0;
	while (cypher_i < len_cypher)
	{
		step_i = 0;
		scanf("%d", &len_step);
		tab_step = (char *)calloc(sizeof(char), len_step);
		scanf("%s\n", tab_step);
		process_step(tab_step, tab_cypher + cypher_i);
		free(tab_step);
		cypher_i++;
	}
}	

void	print_cypher(int *tab_cypher, int len_cypher)
{
	int	cypher_i;

	cypher_i = 0;
	while (cypher_i < len_cypher)
	{
		printf("%d", tab_cypher[cypher_i]);
		if (cypher_i < len_cypher - 1)
			printf(" ");
		cypher_i++;
	}
	printf("\n");
}

int	main(void)
{
	int	len_case_test;
	int	case_test_i;
	int	len_cypher;
	int	cypher_i;
	int	*tab_cypher;

	scanf("%d\n", &len_case_test);
	case_test_i = 0;
	while (case_test_i < len_case_test)
	{
		scanf("%d\n", &len_cypher);
		tab_cypher = (int *)calloc(sizeof(int), len_cypher);
		cypher_i = 0;
		while (cypher_i < len_cypher)
			scanf("%d", &tab_cypher[cypher_i++]);
		resolve_cypher(tab_cypher, len_cypher);
		print_cypher(tab_cypher, len_cypher);
		free(tab_cypher);
		case_test_i++;
	}
	return (0);
}
