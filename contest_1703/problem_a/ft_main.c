#include <stdio.h>
#include <string.h>

int	is_yes(char buff[255])
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] >= 'A' && buff[i] <= 'Z')
			buff[i] += 'a' - 'A';
		i++;
	}
	return (strcmp(buff, "yes"));
}

int	main(void)
{
	int		len_test_case;
	int		test_case_i;
	char	buff[255];

	scanf("%d\n", &len_test_case);
	test_case_i = 0;
	while(test_case_i < len_test_case)
	{
		scanf("%s\n", buff);
		if (is_yes(buff) == 0)
			printf("YES");
		else
			printf("NO");
		printf("\n");
		test_case_i++;
	}
	return (0);
}