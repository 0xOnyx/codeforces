#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 7537

typedef struct s_node
{
	char		*key;
	struct s_node	*next;
} t_node;

int	djb2(char *str)
{
	int	hash;

	hash = 5381;
	while(*str)
	{
		hash = (hash << 5) + hash + *str;
		str++;
	}
	return hash;
}

void	add_h(char *str, t_node **h)
{
	int	index;
	t_node	*new_node;

	index = djb2(str) % TABLE_SIZE;
	new_node = malloc(sizeof(t_node));
	new_node->key = str;
	new_node->next = h[index];
	h[index] = new_node;
}

int	in_h(char *str, t_node **h)
{
	int	index;
	t_node	*current;

	index = djb2(str) % TABLE_SIZE;
	current = h[index];
	while (current)
	{
		if (strcmp(current->key, str) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

int f(char *str, t_node **h)
{
	int	len;
	char	prefix[9];
	char 	*suffix;

	len = strlen(str);
	memset(prefix, 0, 9);
	for(int i = 1; i < len; i++)
	{
		prefix[i - 1] = str[i - 1];
		suffix = str + i;
		if (in_h(prefix, h) && in_h(suffix, h))
			return (1);
	}
	return (0);
}

int main()
{
	int T, n;
	char **s;
	t_node *h[TABLE_SIZE];

	scanf("%d\n", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%d\n", &n);
		s = malloc(n * sizeof(*s));
		for(int i = 0; i < TABLE_SIZE; i++)
			h[i] = 0;
		for(int i = 0; i < n; i++)
		{
			s[i] = malloc(9);
			scanf("%s\n", s[i]);
			add_h(s[i], h);
		}
		for(int i = 0; i < n; i++)
		{
			printf("%d", f(s[i], h));
		}
		printf("\n");
	}
	return (0);
}	
