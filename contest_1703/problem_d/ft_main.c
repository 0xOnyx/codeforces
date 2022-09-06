#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 7537

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

unsigned int	hash_djb2(unsigned char *str)
{
	unsigned long hash;

	hash = 5381;
	while (*str)
		hash = ((hash << 5) + hash) + (int)*str++;
	return (hash);
}

int		is_in_hash(t_node **hash_map, char *str)
{
	int		pos;
	t_node	*current;

	pos = hash_djb2(str) % MAX;
	current = hash_map[pos];
	while (current)
	{
		if (strcmp(current->str, str) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

void	free_hash_map(t_node **hash_map)
{
	t_node	*current;
	t_node	*tmp;
	int i;

	i = 0;
	while (i < MAX)
	{
		current = hash_map[i];
		while (current)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
		i++;
	}
	free(hash_map);
}

void	free_word_buff(char **word_buff, int word_len)
{
	int	i;

	i = 0;
	while (i < word_len)
		free(word_buff[i++]);
	free(word_buff);
}

void	add_to_hash(t_node **hash_map, char *str)
{
	int		pos;
	t_node	*node;

	if (!is_in_hash(hash_map, str))
	{
		pos = hash_djb2((unsigned char *)str) % MAX;
		node = (t_node *)malloc(sizeof(t_node));
		node->next = hash_map[pos];
		node->str = str;
		hash_map[pos] = node;
	}
}

void	init_hash_map(t_node **hash_map, char **word_buff, int world_len)
{
	int		word_i;

	word_i = 0;
	while (word_i < world_len)
	{
		word_buff[word_i] = (char *)calloc(sizeof(char), 9);
		scanf("%s\n", word_buff[word_i]);
		add_to_hash(hash_map, word_buff[word_i]);
		word_i++;
	}
}

int		is_correct_word(t_node **hash_map, char **word_buff, int current)
{
	int	padding;
	char *tmp;
	int	len;

	padding = 1;
	len = strlen(word_buff[current]);
	while (padding < len)
	{
		tmp = strdup(word_buff[current]);
		tmp[padding] = '\0';
		if (is_in_hash(hash_map, word_buff[current] + padding)
			&& is_in_hash(hash_map, tmp))
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		padding++;
	}
	return (0);
}

void	found_foreach_word(t_node **hash_map, char **word_buff, int word_len)
{
	int		word_i;
	int		found_word_i;
	int		len;

	word_i = 0;
	while (word_i < word_len)
	{
		if (is_correct_word(hash_map, word_buff, word_i))
			printf("1");
		else
			printf("0");
		word_i++;
	}
	printf("\n");
}

int	main(void)
{
	int		case_test_len;
	int		case_test_i;
	int		word_len;
	t_node 	**hash_map;
	char	**word_buff;

	case_test_i = 0;
	scanf("%d\n", &case_test_len);
	while (case_test_i < case_test_len)
	{
		scanf("%d\n", &word_len);
		word_buff = (char **)calloc(sizeof(char *), word_len);
		hash_map = (t_node **)calloc(sizeof(t_node *), MAX);
		init_hash_map(hash_map, word_buff, word_len);
		found_foreach_word(hash_map, word_buff, word_len);
		free_hash_map(hash_map);
		free_word_buff(word_buff, word_len);
		case_test_i++;
	}
	return (0);
}