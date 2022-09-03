#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST "Timur"

int	ft_test(char *current_value, char *test_value, int len)
{
	char	ascii[127];
	int	i;

	i = 0;
	memset(ascii, 0, 127);
	while (current_value[i] != '\0' && i < len)
	{
		ascii[(int)current_value[i]] += 1;
		i++;
	}
	i = 0;
	while (test_value[i] != '\0')
	{
		if (ascii[(int)test_value[i]] != 1)
			return (0);
		ascii[(int)test_value[i]] = 0;
		i++;
	}
	i = 0;
	while (i < 127)
	{
		if (ascii[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	char	*current_value;
	int	len_current_value;
	int	len;
	int	i;

	scanf("%d\n", &len);
	i = 0;
	while (i < len)
	{
		scanf("%d\n", &len_current_value);
		if (len_current_value > 0)
		{
			current_value = (char *)calloc(sizeof(char), len_current_value);
			scanf("%255s\n", current_value);
			if (ft_test(current_value, TEST, len_current_value))
				printf("YES\n");
			else
				printf("NO\n");
			free(current_value);
		}
		i++;
	}
}
