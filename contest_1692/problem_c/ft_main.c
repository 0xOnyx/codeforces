#include <stdio.h>
#include <string.h>

int	pos_char(char buff[9])
{
	int i;

	i = 0;
	while (buff[i] != '#' && buff[i])
		i++;
	return (i);
}

int	is_final(char buff[9])
{
	int i;

	if (buff[0] == 0)
		return (0);
	i = pos_char(buff);
	if (i + 2 < 8 && buff[i + 2] == '#')
		return (1);
	return (0);
}

void	game(void)
{
	char	new_buff[9];
	char	old_buff[9];
	int	x;

	x = 0;
	memset(old_buff, 0, 9);
	while (x < 8)
	{
		scanf("%s", new_buff);
		if (is_final(old_buff))
			break ;
		memcpy(old_buff, new_buff, 8);
		x++;
	}
	printf("%d %d\n", x + 1, pos_char(new_buff) + 1);
	while (++x < 8)
		scanf("%s", new_buff);
}

int	main(void)
{
	int	len_test;
	int	test_i;

	test_i = 0;
	scanf("%d", &len_test);
	while (test_i < len_test)
	{
		game();
		test_i++;
	}
	return (0);
}
