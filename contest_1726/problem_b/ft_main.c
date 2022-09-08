#include <stdio.h>
#include <stdlib.h>

void	resolve(char *buff, int len)
{
	char	last;
	int		res;

	res = 1;
	last = *buff;
	buff++;
	while (*buff)
	{
		if (last == '(' && *buff == '(')
			res++;
		last = *buff++;
	}
	printf("%d\n", res);
}

int		main(void)
{
	int		len_test;
	int		test_i;
	int		len_buff;
	char	*buff;

	test_i = 0;
	scanf("%d\n", &len_test);
	while (test_i < len_test)
	{
		scanf("%d\n", &len_buff);
		buff = (char *)calloc(sizeof(char), (len_buff * 2) + 1);
		scanf("%s\n", buff);
		resolve(buff, len_buff);
		free(buff);
		test_i++;
	}
	return (0);
}