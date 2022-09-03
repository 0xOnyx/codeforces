#include <stdio.h>
#include <stdlib.h>

int	ft_test(char *buff_1, char *buff_2, int len)
{
	int	i;

	i = 0;
	while (len > i)
	{
		if ((buff_1[i] == 'G' || buff_1[i] == 'B')
			&& (buff_2[i] == 'G' || buff_2[i] == 'B'))
		{
			i++;
			continue;
		}
		if (buff_1[i] != buff_2[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{
	int	i;
	int	len;
	int	len_buff;
	char	*buff_1;
	char	*buff_2;

	i = 0;
	scanf("%d\n", &len);
	while (i < len)
	{
		scanf("%d\n", &len_buff);
		buff_1 = (char *)calloc(sizeof(char), len_buff + 1);
		buff_2 = (char *)calloc(sizeof(char), len_buff + 1);
		scanf("%255s\n", buff_1);
		scanf("%255s\n", buff_2);
		if (ft_test(buff_1, buff_2, len_buff) != 0)
			printf("NO\n");
		else
			printf("YES\n");
		free(buff_1);
		free(buff_2);
		i++;
	}
	return (0);
}
